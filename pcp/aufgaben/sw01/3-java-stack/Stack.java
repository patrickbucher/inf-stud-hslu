package com.github.patrickbucher.pcp.stack;

public class Stack {

	private Element top = null;

	private int size = 0;

	public void push(Element e) {
		if (top == null) {
			top = e;
		} else {
			e.setNext(top);
			top = e;
		}
		size++;
	}

	public Element top() {
		if (isEmpty()) {
			return null;
		}
		return top;
	}

	public boolean pop() {
		if (top == null) {
			return false;
		}
		top = top.getNext();
		size--;
		return true;
	}

	public void print() {
		if (isEmpty()) {
			System.out.println("print - Stack is empty");
			return;
		}
		System.out.print("print - Stack contains: ");
		for (Element e = top; e != null; e = e.getNext()) {
			System.out.print(e.getValue() + ", ");
		}
		System.out.print("top element = " + top.getValue() + "\n");
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public int size() {
		return size;
	}
}
