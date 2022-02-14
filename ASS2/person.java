class person {

  String id;
  int type; //0== tuor, 1==student
  customLinkedList past_apoinment;
  int Total_past_Apoinment;

  public person(String id, int type) {
    this.id = id;

    this.type = type;
    Total_past_Apoinment = 0;
    past_apoinment = new customLinkedList();
  }

  public void addPastApointmetn(
    String studentName,
    String Topic_taught,
    int hour,
    int revuenue
  ) {
    passApointment temp = new passApointment(
      studentName,
      Topic_taught,
      hour,
      revuenue
    );
    past_apoinment.add(
     null,null, temp
    );
    Total_past_Apoinment++;

  }
}
