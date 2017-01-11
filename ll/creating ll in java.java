package ds;

import java.util.*;
 
public class ll
{
    public static void main(String args[])
    {
    	// creating ll
        LinkedList<String> object = new LinkedList<String>();
 
        // adding elements
        object.add("A");
        object.add("B");
        object.addLast("C");
        object.addFirst("D");
        object.add(2, "E");
        object.add("F");
        object.add("G");
        System.out.println("Linked list : " + object);
 
        //removing elements
        object.remove("B");
        object.remove(3);
        object.removeFirst();
        object.removeLast();
        System.out.println("Linked list after deletion: " + object);
 
        //checking an element
        boolean status = object.contains("E");
 
        if(status)
            System.out.println("List contains the element 'E' ");
        else
            System.out.println("List doesn't contain the element 'E'");
 
        //  finding the size of ll
        int size = object.size();
        System.out.println("Size of linked list = " + size);
 
        //getting and setting an elements
        Object element = object.get(2);
        System.out.println("Element returned by get() : " + element);
        object.set(2, "Y");
        System.out.println("Linked list after change : " + object);
    }
}