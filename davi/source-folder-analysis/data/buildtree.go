// buildtree converts the JSON output from gocloc to a tree structure.
package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strings"
)

// PathSeparator is the separator used in the input data structure.
const PathSeparator = "/"

// SlocStats represents the input data structure.
type SlocStats struct {
	Files []FileEntry
	Total StatsEntry
}

// FileEntry represents the statistics on a single file (leaf).
type FileEntry struct {
	Code    int    `json:"code"`
	Comment int    `json:"comment"`
	Blank   int    `json:"blank"`
	Name    string `json:"name"`
	Lang    string `json:"Lang"`
}

// StatsEntry represents the total statistics.
type StatsEntry struct {
	Files   int `json:"files"`
	Code    int `json:"code"`
	Comment int `json:"comment"`
	Blank   int `json:"blank"`
}

// Node represents a folder or source file in the output tree.
type Node struct {
	Name          string       `json:"name"`
	Code          int          `json:"code"`
	Comment       int          `json:"comment"`
	Blank         int          `json:"blank"`
	Language      string       `json:"language,omitempty"`
	Children      CollapsedMap `json:"children,omitempty"`
	LanguageLines map[string]int
}

// TopLanguage finds the language key with the highest line value in
// LanguageLines and returns it.
func (n *Node) TopLanguage() string {
	maxLines := 0
	var topLang string
	for lang, lines := range n.LanguageLines {
		if lines > maxLines {
			maxLines = lines
			topLang = lang
		}
	}
	return topLang
}

// CollapsedMap is a map that is rendered as an array in JSON.
type CollapsedMap map[string]*Node

// MarshalJSON marshals a map as an array, i.e. by omitting the key.
func (c CollapsedMap) MarshalJSON() ([]byte, error) {
	output := make([]*Node, 0)
	for _, value := range c {
		output = append(output, value)
	}
	return json.Marshal(output)
}

func main() {
	content, err := ioutil.ReadAll(os.Stdin)
	if err != nil {
		log.Fatalf("read from STDIN: %v", err)
	}
	var slocStats SlocStats
	err = json.Unmarshal(content, &slocStats)
	if err != nil {
		log.Fatalf("unmarshal source content: %v", err)
	}
	root := Node{
		Name:          "",
		Code:          0,
		Comment:       0,
		Blank:         0,
		Children:      make(map[string]*Node, 0),
		LanguageLines: make(map[string]int, 0),
	}
	for _, f := range slocStats.Files {
		attach(&root, &f)
	}
	buf, err := json.Marshal(root)
	if err != nil {
		log.Fatalf("marshal tree: %v", err)
	}
	fmt.Println(string(buf))
}

func attach(parent *Node, entry *FileEntry) {
	parent.Code += entry.Code
	parent.Comment += entry.Comment
	parent.Blank += entry.Blank
	pathSegment, pathRemainder := split(entry.Name)
	node, exists := parent.Children[pathSegment]
	if !exists {
		var lang string
		var code, comment, blank int
		if len(pathRemainder) == 0 {
			// leaf
			lang = entry.Lang
			code = entry.Code
			comment = entry.Comment
			blank = entry.Blank
		}
		child := Node{
			Name:          pathSegment,
			Code:          code,
			Comment:       comment,
			Blank:         blank,
			Language:      lang,
			Children:      make(map[string]*Node, 0),
			LanguageLines: make(map[string]int, 0),
		}
		lines := entry.Code + entry.Comment + entry.Blank
		if _, ok := parent.LanguageLines[entry.Lang]; ok {
			parent.LanguageLines[entry.Lang] += lines
		} else {
			parent.LanguageLines[entry.Lang] = lines
		}
		parent.Language = parent.TopLanguage()
		parent.Children[pathSegment] = &child
		node = &child
	}
	reducedName := strings.Join(pathRemainder, PathSeparator)
	if reducedName != "" {
		entry.Name = reducedName
		attach(node, entry)
	}
}

func split(path string) (string, []string) {
	var segment string
	var i int
	segments := strings.Split(path, PathSeparator)
	for i = 0; i < len(segments) && segment == ""; i++ {
		segment = segments[i]
	}
	return segment, segments[i:]
}
