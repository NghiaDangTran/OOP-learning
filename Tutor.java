public class Tutor extends item {

    private   int hour;
    private   customLinkedList topics;
    //int price;
    public Tutor(String id, int hour) {
        super(id, 0);
        this.hour = hour;
        topics = new customLinkedList();
    }

    public boolean addTopic(String topic, int price) {


        MyNode temp = topics.getRoot();
        while (temp != null) {
            if (temp.getData().equals(topic)) {
                System.out.println("Topic already exist");
                return false;
            }
            temp = temp.getNext();
        }
        topics.add( new topic(topic, price));
        return true;
    }

    public int getHour() {
        return hour;
    }
    public int price_topic(String topic_string)
    {
        int result=-1;
        MyNode temp = topics.getRoot();
        while (temp != null) {
            if (((topic) temp.getData()).getTopic().equals(topic_string)) {
                result=((topic) temp.getData()).price;
                break;
            }
            temp = temp.getNext();
        }
        return result;
    }
    public String toString() {
        String result="Tutor: " + super.getName() + " " + hour + " \n";
        topics.printData(4);


        return result;
    }
    public customLinkedList getTopic(){
        return topics;
    }

    public boolean Topic_in_list(String topic){
        MyNode temp = topics.getRoot();
        while (temp != null) {
            if (((topic) temp.getData()).topic.equals(topic)) {
                return true;
            }
            temp = temp.getNext();
        }
        return false;
    }

    public customLinkedList get_Apointment(){
        return super.get_Apointment();
    }
    // public String getName(){
    //   return this.id;
    // }

}



