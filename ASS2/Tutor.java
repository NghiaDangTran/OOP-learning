class Tutor extends person {

    int hour;
    String Topic_taught;
    int price;
    public Tutor(String id, int hour) {
      super(id, 0);
      this.hour = hour;
  
    }
  
    public void addTopic(String topic, int price) {
      this.Topic_taught = topic;
      this.price = price;
    }


    public String toString() {
      return "Tutor: " + id + " " + hour + " " + Topic_taught + " " + price;
    }

    public String getName(){
      return this.id;
    }
  }
  