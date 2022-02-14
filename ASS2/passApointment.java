class passApointment {

    String Id_of_user;
    int Total_Hour_spent;
    int Total_Price;
    String Topic_name;

    public passApointment(
      String user,
      String topic_name,
      int total_Hour_spent,
      int total_Price
    ) {
      this.Id_of_user = user;
      Total_Hour_spent = total_Hour_spent;
      Total_Price = total_Price;
      Topic_name = topic_name;
    }

    public String tostring()
    {
        String str = "";
        str += "person: " + this.Id_of_user + "\n";
        str += "Topic: " + this.Topic_name + "\n";
        str += "Hour: " + this.Total_Hour_spent + "\n";
        str += "Price: " + this.Total_Price + "\n";
        return str;
    }
  }