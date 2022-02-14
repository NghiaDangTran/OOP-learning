
class Student extends person {

  String topic;
  int hour;
  
    public Student(String id) {
      super(id, 1);
      
    }
  
    public void add_topic( String topic, int hour) {
      // this will return boolean if the topic is ok 
      this.topic = topic;
      this.hour = hour;
  
    }

    public String toString() {
      String str = "";
      str += "Student: " + this.id + "\n";
      str += "Topic: " + this.topic + "\n";
      str += "Hour: " + this.hour + "\n";
      return str;
    }
    public String getName(){
      return this.id;
    }
  }
  