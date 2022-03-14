package B_linked;
class check
{

}

///////////////////////////////////
class LinkedList1 {
    Node head;  // head of list

    /* Linked list Node*/
    class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    /* Inserts a new Node at front of the list. */
    public void push(int new_data) {
        /* 1 & 2: Allocate the Node &
                  Put in the data*/
        Node new_node = new Node(new_data);

        /* 3. Make next of new Node as head */
        new_node.next = head;

        /* 4. Move the head to point to new Node */
        head = new_node;
    }

    /* Inserts a new node after the given prev_node. */
    public void insertAfter(Node prev_node, int new_data) {
        /* 1. Check if the given Node is null */
        if (prev_node == null) {
            System.out.println("The given previous node cannot be null");
            return;
        }

        /* 2 & 3: Allocate the Node &
                  Put in the data*/
        Node new_node = new Node(new_data);

        /* 4. Make next of new Node as next of prev_node */
        new_node.next = prev_node.next;

        /* 5. make next of prev_node as new_node */
        prev_node.next = new_node;
    }

    /* Appends a new node at the end.  This method is
       defined inside LinkedList class shown above */
    public void append(int new_data) {
        /* 1. Allocate the Node &
           2. Put in the data
           3. Set next as null */
        Node new_node = new Node(new_data);

        /* 4. If the Linked List is empty, then make the
              new node as head */
        if (head == null) {
            head = new Node(new_data);
            return;
        }

        /* 4. This new node is going to be the last node, so
              make next of it as null */
        new_node.next = null;

        /* 5. Else traverse till the last node */
        Node last = head;
        while (last.next != null)
            last = last.next;

        /* 6. Change the next of last node */
        last.next = new_node;
        return;
    }

    /* This function prints contents of linked list starting from
        the given node */
    public void printList() {
        Node tnode = head;
        while (tnode != null) {
            System.out.print(tnode.data + " ");
            tnode = tnode.next;
        }
    }
}
class LINKED_Listgvhg {


    private Node top;
    private int size;

    public LINKED_Listgvhg() {
        top = null;
        size = 0;
    }

    public String toString() {

        Node begin = top;
        String S = "";
        while (begin != null) {
            S += begin.getData() + " ";
            begin = begin.getNext();
        }
        return S;
    }


    public void modifyList() {

        Node prev = null;
        Node curr = top;


        while (curr != null) {


            if (curr.getData() % 2 == 0) {

                if (prev == null) {
                    top = new Node(curr.getData(), curr);
                } else {
                    Node temp = new Node(curr.getData(), curr);
                    prev.setNext(temp);
                    System.out.println(temp);

                }


            }

            prev = curr;
            curr = curr.getNext();

        }

        removeOdds();

    }


    public void removeOdds() {
        Node cur = top;
        Node previous = cur;
        while (cur.next != null) {
            cur = cur.next;
            if (cur.getData() % 2 != 0) {
                size--;
                previous.next = cur.next;
            } else {
                previous = previous.next;
            }
        }
    }

    public boolean isEmpty() {
        return top == null;

    }

    public void insertLast(int newIndex) {
        Node temp = top;
        Node curr = new Node(newIndex, null);

        if (top == null) {
            top = curr;
            size++;

        } else {
            while (temp != null) {
                if (temp.next == null) {
                    System.out.println(temp.getData());
                    temp.setNext(curr);
                    size++;
                    break;
                }

                temp = temp.getNext();
            }
        }
    }

    public void printMiddle() {
        Node slow_ptr = top;
        Node fast_ptr = top;
        if (top != null) {
            while (fast_ptr != null && fast_ptr.next != null) {
                fast_ptr = fast_ptr.next.next;
                slow_ptr = slow_ptr.next;
            }
            System.out.println("The middle element is [" +
                    slow_ptr.getData() + "] \n");
        }
    }

    public void insertUnordered(int newItem) {
        top = new Node(newItem, top);
        size++;
    }

    public void insertOrdered(int newItem) {
        size++;

        Node prev = null;
        Node curr = top;

        while (curr != null && curr.item < newItem) {
            prev = curr;
            curr = curr.next;
        }
        Node newNode = new Node(newItem, curr);
        if (prev != null)
            prev.next = newNode;
        else
            top = newNode;


    }

    Node find(int key) {
        Node curr = top;
        while (curr != null && curr.item != key)
            curr = curr.next;
        if (curr != null && curr.getData() != key)
            curr = null;
        return curr;
    }

    public void delete_first() {
        top = top.next;
        size--;

    }


    public void deleteSecondLast() {
        //        Node temp = top;
        //
        //        if (temp != null && temp.getNext() != null) {
        //            Node secondtemp = temp.getNext();
        //            while (temp != null&&secondtemp!=null)
        //
        //            {
        //                if(secondtemp.getNext()==null)
        //                {
        //                    size--;
        //                    temp
        //                }
        //            }
        //
        //
        //        }


    }

    public void moveMin() {
        Node min, prevMin;
        Node curr, prev;


        if ((top != null) && (top.next != null)) {
            prevMin = null;
            ;
            min = top;
            prev = top;
            curr = top.getNext();
            while (curr != null) {
                if (curr.getData() < min.getData()) {
                    prevMin = prev;
                    min = curr;
                }
                prev = curr;
                curr = curr.getNext();
            }

            if (top != null) {
                prevMin.setNext(min.getNext());
                min.setNext(top);
                top = min;
            }

        }
    }

    public void deleteLast() {
        Node temp = top;

        if (top != null) {
            while (temp != null) {
                if (temp.getNext() == null) {
                    temp = null;
                    size--;
                    break;


                }
                temp = temp.getNext();
            }

        }


    }

    public void delete(int key) {

        Node prev = null;
        Node curr = top;
        while ((curr != null) && (curr.item != key)) {
            prev = curr;
            curr = curr.next;
        }

        if (curr != null) {
            if (prev != null) {
                prev.next = curr.next;
                size--;
            } else {
                top = curr.next;
                size--;
            }
        }
    }
    // and other method


    private class Node {
        public int item;
        public Node next;

        public Node(int newitme, Node NExt) {
            item = newitme;
            next = NExt;
        }

        public int getData() {
            return item;
        }

        public Node getNext() {
            return next;
        }

        public void setNext(Node nextI) {
            next = nextI;
        }

        public String toString() {
            String S = "" + item;
            return S;
        }
    }
}
