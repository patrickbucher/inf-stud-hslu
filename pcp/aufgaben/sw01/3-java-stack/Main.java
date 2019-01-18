package com.github.patrickbucher.pcp.stack;

public class Main {

	public static void main(String[] args) {
		Stack myStack = new Stack();
		System.out.println("myStack.size() = " + myStack.size());
		System.out.println("myStack.isEmpty() = " + myStack.isEmpty());
		myStack.print();
		myStack.top();
		myStack.push(new Element(42));
		myStack.push(new Element(77));
		myStack.push(new Element(1));
		System.out.println("myStack.size() = " + myStack.size());
		System.out.println("myStack.isEmpty() = " + myStack.isEmpty());
		myStack.print();
		myStack.push(new Element(33));
		myStack.pop();
		myStack.push(new Element(33));
		myStack.print();
		Element e = myStack.top();
		System.out.println("top Element is " + e.getValue());
	}
}