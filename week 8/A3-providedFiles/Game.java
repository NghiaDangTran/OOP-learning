public class Game implements GameLogicable {

    private Handable humanHand;
    private Handable cpuHand;
    private Deck deck;
    private int state;
    private String[] messages;

    public Game() {
        humanHand = new Hand();
        cpuHand = new Hand();
        deck = new Deck();

      

        ( humanHand).draw(deck, true);
        ( humanHand).draw(deck, true);
        ( humanHand).draw(deck, true);
        (humanHand).draw(deck, true);
         ( humanHand).draw(deck, true);
         



        ( cpuHand).draw(deck, true);
        ( cpuHand).draw(deck, true);
        ( cpuHand).draw(deck, true);
        ( cpuHand).draw(deck, true);
        ( cpuHand).draw(deck, true);
       
    }

    @Override
    public Handable getCPUHand() {
        // TODO Auto-generated method stub
        return cpuHand;
    }

    @Override
    public Handable getHumanHand() {
        // TODO Auto-generated method stub
        return humanHand;
    }

    @Override
    public boolean nextState(String[] messages) {

     
      
      if (state==0)
      {
          messages[0] = "Beginnig of game 1";
      }
      ( humanHand).draw(deck, true);
      ( humanHand).draw(deck, true);
      ( humanHand).draw(deck, true);
      (humanHand).draw(deck, true);
       ( humanHand).draw(deck, true);
       
        return true;
    }
    
}
