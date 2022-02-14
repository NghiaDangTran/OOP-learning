public class customLinkedList {
    class MyNode {
        
        private Student student;
        private Tutor tutor;
        private passApointment pastApoinment;
        
        private MyNode next;
        public MyNode(Student student) {

            this.student = student;
            this.next = null;
        }
        public MyNode(Tutor tutor) {
            this.tutor = tutor;
            this.next = null;
        }
        public MyNode(passApointment pastApoinment) {
            this.pastApoinment = pastApoinment;
            this.next = null;
        }
        public Student getStudent() {
            return student;
        }
        public Tutor getTutor() {
            return tutor;
        }
        public passApointment getPastApoinment() {
            return pastApoinment;
        }

    }
    private MyNode root;
    private int size;
    public customLinkedList() {
        this.root = null;
        this.size = 0;
    }
    public void add(Student student,Tutor tutor,passApointment pastApoinment) {
        //this is just one way to implement the insert method
        //you can rewrite to use your own implementation

        MyNode node ;
        if (student != null) {
            node = new MyNode(student);
        } else if(tutor!=null){
            node = new MyNode(tutor);
        }
        else node=new MyNode(pastApoinment);

        if (root == null) {
            root = node;
        } else {
            MyNode currentNode = root;
            while (currentNode.next != null) {
                currentNode = currentNode.next;
            }
            currentNode.next = node;
        }
        size++;
    }
   
    public void printData(int type) {
        //method used to print the content of the linked list
        MyNode currentNode = root;
        while (currentNode != null) {
                if (type == 1 ){
                    System.out.println(currentNode.getStudent());
                } else {
                    System.out.println(currentNode.getTutor());
                }
                    currentNode = currentNode.next;
        }
    }

    // public static void main(String[] args)
    // {
    //     customLinkedList Student_List = new customLinkedList();
    //     Student student1 = new Student("Johnq");
    //     student1.add_topic("Java", 1);
    //     Student student2 = new Student("Jane1");
    //     student2.add_topic("Java123", 100);

    //     Student student3 = new Student("John2");    

    //     student3.add_topic("Java.0", 100);
    //     Student_List.add(student1,null,null);
    //     Student_List.add(student2,null,null);
    //     Student_List.add(student3,null,null);
    //     Student_List.printData(1);
    // }
}