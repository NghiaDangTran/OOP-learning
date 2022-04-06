
public class Card  implements Cardable {
    private int number;
    private Suit suit;
    private boolean selected;
    private boolean face_up;
    public Card(int number, Suit suit){
        this.number = number;
        this.suit = suit;
        this.selected = false;
        // randomly set face_up to true or false
        this.face_up =false;
        
    }

    
    public boolean getSelected() {
        return selected;
    }


    
    public boolean getFaceUp() {
        return face_up;
    }

    
 

    
    public void switchSelectedState() {
        selected = !selected;
        
    }

    
    public void resetSelected() {
        selected = false;
        
        
    }

    
    public void setFaceUp(boolean faceUp2) {
        face_up = faceUp2;
        
        
    }

    public String toString(){
     
        String reusult="";
        if (number>=0 && number<=8){
            reusult = ""+(number+2);
        }
      
        else if (number==9){
            reusult = "J";
        }
        else if (number==10){
            reusult = "Q";
        }
        else if (number==11){
            reusult = "K";
        }
        else if (number==12){
            reusult = "A";
        }
        return  reusult + suit_string();
    }
    public String suit_string(){
        if (suit == Suit.HEART){
            return "\u2665";
        }
        else if (suit == Suit.DIAMOND){
            return  "\u2666";
        }
        else if (suit == Suit.SPADE){
            return "\u2660";
        }
        else{
            return "\u2663";
        }
    }
    public int getNumber(){
        return number;
    }
    public Suit getSuit(){
        return suit;
    }
//     public int SuitCompare(card other){
    
// return        Suit.valueOf(this.suit.toString()).ordinal()-Suit.valueOf(other.suit.toString()).ordinal();
//     }
    
    public int compareTo(Cardable c){
    //    Card c_copy=(Card)c;
        if (this.getNumber()>((Card)c).getNumber()){
            return 1;
        }
       else if (this.getNumber()==((Card)c).getNumber()){
        
            return 0;
        }
       
        else {
            return -1;
        }
       
    }
}
