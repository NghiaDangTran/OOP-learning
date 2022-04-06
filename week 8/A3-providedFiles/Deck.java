import java.util.LinkedList;


import java.util.Collections;
public class Deck  implements Deckable {
    private LinkedList<Cardable> deck;
    
    public Deck(){
        deck = new LinkedList<Cardable>();
        
            for (int j = 0; j <= 12; j++){
                for (int k = 0; k < 4; k++){
                    Cardable card = new Card(j,Cardable.Suit.values()[k]);
                    deck.add(card);
                }
                
            }
        
        shuffle();
    }

    public void shuffle() {
        Collections.shuffle(deck);  //shuffle the deck
        
    }

    @Override
    public void returnToDeck(LinkedList<Cardable> discarded) {
        deck.addAll(discarded);  //add the discarded cards back to the deck
        
    }

    @Override
    public Cardable drawACard(boolean faceUp) {
        // TODO Auto-generated method stub
        return deck.remove();
    }

    public String toString(){
        String result = "";
        for (Cardable card: deck){
            result += card.toString() + " ";
        }
        return result;
    }
    
}
