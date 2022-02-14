import java.util.Arrays;
import java.util.Random;

public class main {

  public static void main(String[] args) {
   customLinkedList student_list=new customLinkedList();
    customLinkedList tutor_list=new customLinkedList();
  
    Tutor tutor1=new Tutor("tutor1",10);
    tutor1.addTopic("java",100);
    tutor_list.add(null,tutor1,null);
    Tutor tutor2=new Tutor("tutor2",10);
    tutor2.addTopic("java2",100);
    tutor_list.add(null,tutor2,null);


    Student student1=new Student("student1");
    student1.add_topic("java",10);
    student_list.add(student1,null,null);
    Student student2=new Student("student2");
    student2.add_topic("java2",10);
    student_list.add(student2,null,null);
    Student student3=new Student("student3");
    student3.add_topic("java3",10);
    student_list.add(student3,null,null);
    Student student4=new Student("student4");
    student4.add_topic("java4",10);
    student_list.add(student4,null,null);





    student_list.printData(1);


  }

  private static int get_the_tutor(Tutor[] data, String topic, int max) {
    int curr = 10;
    int price = 0;
    int hour = 0;
    String Id = "";
    int result = 0;
    for (int i = 0; i < max; i++) {
      if (data[i].Topic_taught.equals(topic)) {
        curr = i;
        price = data[i].price;
        hour = data[i].hour;
        Id = data[i].id;

        break;
      }
    }

    for (int i = curr + 1; i < max; i++) {
      if (data[i].Topic_taught.equals(topic)) {
        if (data[i].hour > 0) if (data[i].price < price) {
          price = data[i].price;
          hour = data[i].hour;
          Id = data[i].id;

          result = i;
        } else if (data[i].price == price) {
          if (data[i].hour > hour) {
            price = data[i].price;
            hour = data[i].hour;
            Id = data[i].id;

            result = i;
          } else if (data[i].hour == hour) {
            if (data[i].id.compareTo(Id) < 0) {
              price = data[i].price;
              hour = data[i].hour;
              Id = data[i].id;

              result = i;
            }
          }
        }
      } else break;
    }

    return result;
  }
}
/*abstract

we dont need student array 
when student call just 
*/
