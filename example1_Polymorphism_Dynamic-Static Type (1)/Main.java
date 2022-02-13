public class Main {

  public static void main(String[] args) {
    GrandParent gpObject;
    gpObject = new GrandParent();

    // static type - compile time type of gpObject : GrandParent
    // dynamic type - run time type of gpObject : GrandParent

    // we only care about the dynamic type of our object - polymorphic methods
    gpObject.methodX(); // output "Grand Parent"

    gpObject = new Parent(); // error?
    // static: GrandParent dynamic: Parent

    gpObject.methodX(); // Parent

    // Child chObject = new Parent(); //[Error]
    // chObject.methodX(); output/error?

    gpObject = new Child(); // error?
    // s:GP d:Ch
    gpObject.methodX(); // Child

    gpObject = new Child();
    gpObject.onlyGP(); // Only GP

    gpObject = new GrandParent();
    // gpObject.onlyCH(); //error? we always check the higher classes in the
    // hierarchy

    gpObject = new Child();
    gpObject.methodZ(); // output?error?
  }
}

// class subClass extends superClass

class GrandParent {

  // polymorphic method
  public void methodX() {
    System.out.println("Grand Parent");
  }

  public void onlyGP() {
    System.out.println("Only GP");
  }

  public void methodZ() {
    System.out.println("method Z - GP");
  }
}

class Parent extends GrandParent {

  public void methodX() {
    System.out.println("Parent");
  }

  public void methodZ() {
    System.out.println("method Z - P");
  }
}

class Child extends Parent {

  public void methodX() {
    System.out.println("Child");
  }

  public void onlyCH() {
    System.out.println("Only CH");
  }
}

class person {

  class inside {

    int type;
    String tutorTopic; // student topic
    int tutorHour; // student hour
    int tutorPrice;

    public inside(int type, String tutorTopic, int tutorHour, int tutorPrice) {
      this.type = type;
      this.tutorTopic = tutorTopic;
      this.tutorHour = tutorHour;
      this.tutorPrice = tutorPrice;
    }
  }

  String id;
  inside contains[];
  int total;
  int type; //0== tuor, 1==student

  public person(String id, int type) {
    this.id = id;
    contains = new inside[10];
    total = 0;
    this.type = type;
  }

  public void add(int type, String topic, int hour, int price) {
    inside temp = new inside(type, topic, hour, price);
    if (total < 10) {
      contains[total] = temp;
      total++;
    } else {
      inside temp2[] = new inside[contains.length * 2];
      for (int i = 0; i < contains.length; i++) {
        temp2[i] = contains[i];
      }
      contains = temp2;
      contains[total] = temp;
      total++;
    }
  }

  public void remove(int index) {
    if (index < total) {
      for (int i = index; i < total; i++) {
        contains[i] = contains[i + 1];
      }
      total--;
    }
  }
}
class appoinment {

  String studentId;
  String topic;
  String hour;
  String price;

  public appoinment(
    String studentId,
    String topic,
    String hour,
    String price
  ) {
    this.studentId = studentId;
    this.topic = topic;
    this.hour = hour;
    this.price = price;
  }
}
////////////////////////////////////////////////////////
class Tutor extends person  {

  //   String topic;
  //   int price;


  appoinment appoinment[];

  public Tutor(String id) {
    super(id, 0);
    appoinment = new appoinment[10];
  }

  public void addApoinmetn(
    String studentId,
    String topic,
    String hour,
    String price
  ) {
    appoinment temp = new appoinment(studentId, topic, hour, price);
    if (total < 10) {
      appoinment[total] = temp;
      total++;
    } else {
      appoinment temp2[] = new appoinment[appoinment.length * 2];
      for (int i = 0; i < appoinment.length; i++) {
        temp2[i] = appoinment[i];
      }
      appoinment = temp2;
      appoinment[total] = temp;
      total++;
    }
  }

public void add(int type,String topic,int hour,int price){
  super.add(type,topic,hour,price);
}
public void remove(int index){
  super.remove(index);
}

}

class Student extends person {

  //   String topic;
  //   int hour;

  public Student(String id) {
    super(id, 1);
    // this.topic = topic;
    // this.hour = hour;
  }
}
