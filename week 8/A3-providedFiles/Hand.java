import java.io.*;
import java.util.*;

public class Hand implements TestableHand {

  public enum rank {
    Straight_Flush, //1
    Four_Of_A_Kind, //2
    Full_house, //3
    Flush, //4
    Straight, //5
    Three_Of_A_Kind, //6
    Two_Pairs, //7
    Pair, //8
    Nothing, //9
  }

  private ArrayList<Cardable> hand;
  // private Deck deck;
  private ArrayList<Integer> frequency;
  // public static int cheat = 0;

  public Hand() {
    hand = new ArrayList<Cardable>();
    
    // frequency = new ArrayList<Integer>();

    
  }

  public ArrayList<Cardable> getHand() {
    return hand;
  }

  public ArrayList<Integer> getFrequency() {
    return frequency;
  }

  public ArrayList<Integer> getNUmber() {
    ArrayList<Integer> number = new ArrayList<Integer>();
    for (int i = 0; i < hand.size(); i++) {
      number.add(((Card) hand.get(i)).getNumber());
    }
    return number;
  }

  @Override
  public int compareTo(Handable o) {
   
    rank r1 = Getrank();

    System.out.println("r1: "+evaluateHand());
  

    rank r2 = ((Hand) o).Getrank();
    System.out.println("r2: "+o.evaluateHand());
   

   
    if (r1 == r2) 
    {
      if (r1 == rank.Straight_Flush) {
        // if this get 4 is 12 or 0. get hand is 12
        return this.getCard(4).compareTo(o.getCard(4));
      } else if (r1 == rank.Four_Of_A_Kind) {
        int value1 = 0;
        int at1 = 0;
        int value2 = 0;
        int at2 = 0;
        for (int i = 1; i < 4; i += 2) {
          if (this.getFrequency().get(i) == 4) {
            value1 = this.getFrequency().get(i - 1);
          }
          if (((Hand) o).getFrequency().get(i) == 4) {
            value2 = ((Hand) o).getFrequency().get(i - 1);
          }
        }
        if (value1 == value2) {
          ArrayList<Integer> number1 = this.getNUmber();
          int lastnumber1 = 0;
          ArrayList<Integer> number2 = ((Hand) o).getNUmber();
          int lastnumber2 = 0;
          for (Integer i : number1) if (number1.get(i) != value1) lastnumber1 =
            number1.get(i);
          for (Integer i : number2) if (number2.get(i) != value2) lastnumber2 =
            number2.get(i);
          return lastnumber1 - lastnumber2;
        } else return value1 - value2;
      } else if (r1 == rank.Full_house) {
        int value1_3 = 0;
        int value2_3 = 0;
        int value1_2 = 0;
        int value2_2 = 0;
        for (int i = 3; i >=1; i -= 2) {
          if (this.getFrequency().get(i) == 3) {
            value1_3 = this.getFrequency().get(i - 1);
          }

          if (this.getFrequency().get(i) == 2) {
            value1_2 = this.getFrequency().get(i - 1);
          }

          if (((Hand) o).getFrequency().get(i) == 3) {
            value2_3 = ((Hand) o).getFrequency().get(i - 1);
          }
          if (((Hand) o).getFrequency().get(i) == 2) {
            value2_2 = ((Hand) o).getFrequency().get(i - 1);
          }
        }

        if (value1_3 == value2_3) {
          return value1_2 - value2_2;
        }
        return value1_3 - value2_3;
      } else if (r1 == rank.Flush) {
        for (int i = 4; i >= 0; i--) {
          if (this.getCard(i).compareTo(o.getCard(i)) != 0) {
            return this.getCard(i).compareTo(o.getCard(i));
          }
        }
      } else if (r1 == rank.Straight) {
        return this.getCard(4).compareTo(o.getCard(4));
        // return hand.get(4).compareTo(o.getHand().get(4));
      } else if (r1 == rank.Three_Of_A_Kind) {
        int value1_3 = 0;
        int value1_alone1 = 0;
        int value1_alone2 = 0;
        int value2_3 = 0;
        int value2_alone1 = 0;
        int value2_alone2 = 0;
        for (int i = 5; i >=1; i -= 2) {
          if (this.getFrequency().get(i) == 3) {
            value1_3 = this.getFrequency().get(i - 1);
          }
          if (this.getFrequency().get(i) == 1) {
            if (value1_alone1 == 0) {
              value1_alone1 = this.getFrequency().get(i - 1);
            } else {
              value1_alone2 = this.getFrequency().get(i - 1);
            }
          }
          if (((Hand) o).getFrequency().get(i) == 3) {
            value2_3 = ((Hand) o).getFrequency().get(i - 1);
          }
          if (((Hand) o).getFrequency().get(i) == 1) {
            if (value2_alone1 == 0) {
              value2_alone1 = ((Hand) o).getFrequency().get(i - 1);
            } else {
              value2_alone2 = ((Hand) o).getFrequency().get(i - 1);
            }
          }
        }
        if (value1_3 == value2_3) {
          if (value1_alone1 == value2_alone1) {
            return value1_alone2 - value2_alone2;
          }
          return value1_alone1 - value2_alone1;
        }
        return value1_3 - value2_3;
        // return hand.get(0).compareTo(o.getHand().get(0));
      } else if (r1 == rank.Two_Pairs) {
        int value1_2 = 0;
        int value1_22 = 0;
        
        int value1_alone = 0;
        int value2_2 = 0;
        int value2_22 = 0;
        int value2_alone = 0;

        for (int i = 5; i >=1; i -= 2) {
          if (this.getFrequency().get(i) == 2) {
            if (value1_2 == 0) {
              value1_2 = this.getFrequency().get(i - 1);
            } else {
              value1_22 = this.getFrequency().get(i - 1);
            }
          }
          if (this.getFrequency().get(i) == 1) {
            value1_alone = this.getFrequency().get(i - 1);
          }
          if (((Hand) o).getFrequency().get(i) == 2) {
            if (value2_2 == 0) {
              value2_2 = ((Hand) o).getFrequency().get(i - 1);
            } else {
              value2_22 = ((Hand) o).getFrequency().get(i - 1);
            }
          }
          if (((Hand) o).getFrequency().get(i) == 1) {
            value2_alone = ((Hand) o).getFrequency().get(i - 1);
          }

        }
        if (value1_2 == value2_2) {
          if (value1_22 == value2_22) {
            return value1_alone - value2_alone;
          }
          return value1_22 - value2_22;
        }
        return value1_2 - value2_2;
      } 
      else if (r1 == rank.Pair) {
        int value1_2 = 0;
        int value2_2 = 0;
        for (int i = 7; i >=1; i -= 2)
        {
          if (this.getFrequency().get(i) == 2) {
            value1_2 = this.getFrequency().get(i - 1);
          }
          if (((Hand) o).getFrequency().get(i) == 2) {
            value2_2 = ((Hand) o).getFrequency().get(i - 1);
          }
        }
        ArrayList<Integer> number1 =  this.getFrequency();
        ArrayList<Integer> number2 = ((Hand) o).getFrequency();
        for (int i=0;i<number1.size();i+=2) {
          if (number1.get(i) == value1_2) {
            number1.remove(i);
            number1.remove(i);
          }
        }
        for (int i=0;i<number2.size();i+=2) {
          if (number2.get(i) == value2_2) {
            number2.remove(i);
            number2.remove(i);
          }
        }
        if(value1_2 == value2_2) {
         for (int i=number1.size()-1;i>=1;i-=2) {
            if (number1.get(i) != number2.get(i)) {
              return number1.get(i-1) - number2.get(i-1);
            }
         }
         return 0;
        }
        return value1_2 - value2_2;
      }
      
      else {
        for (int i = 4; i >=0; i -= 1) {
         if (this.getCard(i).compareTo(o.getCard(i)) != 0) {
           return this.getCard(i).compareTo(o.getCard(i));
         }
        
        }
        return 0;
      }
    } 


      System.out.println(r1.ordinal());
      System.out.println(r2.ordinal());
     if (r1.ordinal() 
     < r2.ordinal()) {
      //  System.out.println("return r1 bigger than r2");
       return 1;
     } else {
      // System.out.println("return r2 bigger than r1");

       return -1;
     }
    
    // return 0;
  }

  @Override
  public Cardable getCard(int i) {
//    System.out.println(hand.get(i));

    return hand.get(i);
    // return null;
  }

  @Override
  public void draw(Deckable d, boolean faceUp) {
    // TODO Auto-generated method stub

    hand.add(d.drawACard(faceUp));

      if (hand.size() == Handable.HAND_SIZE) {
        Collections.sort(hand);
      if (
        ((Card) hand.get(0)).getNumber() == 0 &&
        ((Card) hand.get(1)).getNumber() == 1 &&
        ((Card) hand.get(2)).getNumber() == 2 &&
        ((Card) hand.get(3)).getNumber() == 3 &&
        ((Card) hand.get(4)).getNumber() == 12
      ) {
        // delete ((card) hand.get(4)) add it to the front
        Cardable.Suit temp = ((Card) hand.get(4)).getSuit();
        hand.remove(4);
        hand.add(0, new Card(12, temp));
      }
      frequency = new ArrayList<Integer>();
      frequency = frequencyNumber(hand, hand.size());
      }
     
  }

  @Override
  public void showAllCards() {
    
    for (int i = 0; i < hand.size(); i++) {
     hand.get(i).setFaceUp(true);
    }

  }

  @Override
  public LinkedList<Cardable> discard() {
    LinkedList<Cardable> discard = new LinkedList<Cardable>();
    for (int i = 0; i < hand.size(); i++) {
      if (hand.get(i).getSelected()) {
        discard.add(hand.get(i));
      }
     
    }
    return discard;
  }

  @Override
  public LinkedList<Cardable> returnCards() {
    // TODO Auto-generated method stub
    LinkedList<Cardable> cards = new LinkedList<Cardable>();
    for (int i = 0; i < hand.size(); i++) {
      cards.add(hand.get(i));
    }
    hand.clear();
    return cards;
  }
  @Override
  public void addCards(Cardable[] cards) {
    // TODO Auto-generated method stub
      for (int i = 0; i < cards.length; i++) {
        this.hand.add(cards[i]);
      }
       if (hand.size() == Handable.HAND_SIZE) {
        Collections.sort(hand);
      if (
        ((Card) hand.get(0)).getNumber() == 0 &&
        ((Card) hand.get(1)).getNumber() == 1 &&
        ((Card) hand.get(2)).getNumber() == 2 &&
        ((Card) hand.get(3)).getNumber() == 3 &&
        ((Card) hand.get(4)).getNumber() == 12
      ) {
        // delete ((card) hand.get(4)) add it to the front
        Cardable.Suit temp = ((Card) hand.get(4)).getSuit();
        hand.remove(4);
        hand.add(0, new Card(12, temp));
      }
      frequency = new ArrayList<Integer>();
      frequency = frequencyNumber(hand, hand.size());
      // System.out.println(frequency.toString());
      
      }
  }
  @Override
  public String evaluateHand() {
    // TODO Auto-generated method stub

    // System.out.println(hand);
    // System.out.println(frequency);
   
    int temp = Math.min(
      Straight_Flush(hand),
      Math.min(
        four_of_a_kind(hand),
        Math.min(
          full_house(hand),
          Math.min(
            getFlush(hand),
            Math.min(
              Stright(hand),
              Math.min(
                three_of_a_kind(hand),
                Math.min(two_pairs(hand), pair(hand))
              )
            )
          )
        )
      )
    );

    // System.out.println("mins: " + temp);
    rank value = rank.values()[temp - 1];
    // System.out.println(":W@@#@#&Y &@#!&    " + value);
    return value.toString();
   
  }

  public Hand.rank Getrank() {
    
    // System.out.println(handData);
    int temp = Math.min(
      Straight_Flush(hand),
      Math.min(
        four_of_a_kind(hand),
        Math.min(
          full_house(hand),
          Math.min(
            getFlush(hand),
            Math.min(
              Stright(hand),
              Math.min(
                three_of_a_kind(hand),
                Math.min(two_pairs(hand), pair(hand))
              )
            )
          )
        )
      )
    );
    rank value = rank.values()[temp - 1];
 
    return value;
  }

  public ArrayList<Integer> numbers(ArrayList<Cardable> data) {
    ArrayList<Integer> result = new ArrayList<Integer>();
    for (int i = 0; i < data.size(); i++) {
      result.add(((Card) data.get(i)).getNumber());
    }

    return result;
  }

  public int Straight_Flush(ArrayList<Cardable> data) {
    if (getFlush(data) == 4) {
      if (
       ((Card) data.get(0)).getNumber() == 12 &&
       ((Card) data.get(1)).getNumber() == 0 &&
       ((Card) data.get(2)).getNumber() == 1 &&
       ((Card) data.get(3)).getNumber() == 2 &&
       ((Card) data.get(4)).getNumber() == 3 
      ) return 1;

      for (int i = 0; i < data.size() - 1; i++) {
        if (
          ((Card) data.get(i)).getNumber() +
          1 !=
          ((Card) data.get(i + 1)).getNumber()
        ) {
          return 9;
        }
      }
    } else return 9;

    return 1;
  }

  public int four_of_a_kind(ArrayList<Cardable> data) {
    if (frequency.size() == 2 * 2) if (
      frequency.get(1) == 4 || frequency.get(3) == 4
    ) return 2;

    return 9;
  }

  public int full_house(ArrayList<Cardable> data) {
    if (frequency.size() == 2 * 2) if (
      (frequency.get(1) == 3 && frequency.get(3) == 2) ||
      (frequency.get(1) == 2 && frequency.get(3) == 3)
    ) return 3;

    return 9;
  }

  public int getFlush(ArrayList<Cardable> data) {
    for (int i = 0; i < data.size() - 1; i++) {
      if (data.get(i).getSuit() != data.get(i + 1).getSuit()) {
        return 9;
      }
    }
    return 4;
  }

  public int Stright(ArrayList<Cardable> data) {
    if (
       ((Card) data.get(0)).getNumber() == 12 &&
       ((Card) data.get(1)).getNumber() == 0 &&
       ((Card) data.get(2)).getNumber() == 1 &&
       ((Card) data.get(3)).getNumber() == 2 &&
       ((Card) data.get(4)).getNumber() == 3 
      ) return 5;
    for (int i = 0; i < data.size() - 1; i++) {
      if (
        ((Card) data.get(i)).getNumber() +
        1 !=
        ((Card) data.get(i + 1)).getNumber()
      ) {
        return 9;
      }
    }

    return 5;
  }

  public int three_of_a_kind(ArrayList<Cardable> data) {
    if (frequency.size() == 3 * 2) if (
      (
        frequency.get(1) == 3 && frequency.get(3) == 1 && frequency.get(5) == 1
      ) ||
      (
        frequency.get(1) == 1 && frequency.get(3) == 3 && frequency.get(5) == 1
      ) ||
      (frequency.get(1) == 1 && frequency.get(3) == 1 && frequency.get(5) == 3)
    ) return 6;

    return 9;
  }

  public int two_pairs(ArrayList<Cardable> data) {
    if (frequency.size() == 3 * 2) if (
      (frequency.get(1) == 2 && frequency.get(3) == 2) ||
      (frequency.get(1) == 2 && frequency.get(5) == 2) ||
      (frequency.get(5) == 2 && frequency.get(3) == 2)
    ) return 7;

    return 9;
  }

  public int pair(ArrayList<Cardable> data) {
    if (frequency.size() == 4 * 2) if (
      (
        frequency.get(1) == 2 &&
        frequency.get(3) == 1 &&
        frequency.get(5) == 1 &&
        frequency.get(7) == 1
      ) ||
      (
        frequency.get(1) == 1 &&
        frequency.get(3) == 2 &&
        frequency.get(5) == 1 &&
        frequency.get(7) == 1
      ) ||
      (
        frequency.get(1) == 1 &&
        frequency.get(3) == 1 &&
        frequency.get(5) == 2 &&
        frequency.get(7) == 1
      ) ||
      (
        frequency.get(1) == 1 &&
        frequency.get(3) == 1 &&
        frequency.get(5) == 1 &&
        frequency.get(7) == 2
      )
    ) return 8;
    return 9;
  }

  public ArrayList<Integer> frequencyNumber(ArrayList<Cardable> arr, int size) {
    // Creating a HashMap containing integer
    // as a key and occurrences as a value
    HashMap<Integer, Integer> data = new HashMap<Integer, Integer>();

    ArrayList<Integer> result = new ArrayList<Integer>();
    for (int i = 0; i < size; i++) {
      if (data.containsKey(((Card) arr.get(i)).getNumber())) {
        data.put(
          ((Card) arr.get(i)).getNumber(),
          data.get(((Card) arr.get(i)).getNumber()) + 1
        );
      } else {
        data.put(((Card) arr.get(i)).getNumber(), 1);
      }
    }

    // data
    //   .entrySet()
    //   .forEach(
    //     entry -> {
    //       System.out.println(entry.getKey() + " " + entry.getValue());
    //     }
    //   );
    data
      .entrySet()
      .forEach(
        entry -> {
          result.add((int) entry.getKey());
          result.add((int) entry.getValue());
        }
      );

    return result;
  }
  public String toString() {
    String s ="[";
    for (int i=0;i<HAND_SIZE;i++) {
      s+=hand.get(i) + " ";

    }

    return s;

  }
  public void Remove_all(){
    hand=new ArrayList<Cardable>();
    frequency=new ArrayList<Integer>();
  }

 
}
