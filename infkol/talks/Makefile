all: 1-managerial-skills/summary-q-a-bucher-christensen.pdf 2-kafka/summary-q-a-bucher.pdf 3-agile/summary-q-a-bucher.pdf 4-containers/summary-q-a-bucher.pdf 5-mongodb/summary-q-a-bucher.pdf

1-managerial-skills/summary-q-a_bucher-christensen.pdf: 1-managerial-skills/*.md
	pandoc $^ -t ms -o $@

2-kafka/summary-q-a-bucher.pdf: 2-kafka/*.md
	pandoc $^ -t ms -o $@

3-agile/summary-q-a-bucher.pdf: 3-agile/*.md
	pandoc $^ -t ms -o $@

4-containers/summary-q-a-bucher.pdf: 4-containers/*.md
	pandoc $^ -t ms -o $@

5-mongodb/summary-q-a-bucher.pdf: 5-mongodb/*.md
	pandoc $^ -t ms -o $@

clean:
	rm -f 1-managerial-skills/summary-q-a-bucher-christensen.pdf
	rm -f 2-kafka/summary-q-a-bucher.pdf
	rm -f 3-agile/summary-q-a-bucher.pdf
	rm -f 4-containers/summary-q-a-bucher.pdf
	rm -f 5-mongodb/summary-q-a-bucher.pdf
