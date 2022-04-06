// import static org.junit.jupiter.api.Assertions.assertEquals;
// import static org.junit.jupiter.api.Assertions.assertNull;
// import static org.junit.jupiter.api.Assertions.assertTrue;


// import org.junit.jupiter.api.DisplayName;
// import org.junit.jupiter.api.Test;
// import org.junit.jupiter.params.ParameterizedTest;
// import org.junit.jupiter.params.provider.CsvSource;


// public class JUnitTests {

//   @Test
//   // straight flush comapre to all orther hand
//   public void test1() {
//     Cardable[] cards1 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(10, Cardable.Suit.CLUB),
//       new Card(11, Cardable.Suit.CLUB),
//       new Card(12, Cardable.Suit.CLUB),
//     };
//     TestableHand th1 = (TestableHand) new Hand();
//     th1.addCards(cards1);

//     TestableHand th2 = (TestableHand) new Hand();
//     Cardable[] cards2 = {
//       new Card(8, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(11, Cardable.Suit.DIAMOND),
//       new Card(12, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards2);
//     assertTrue(th1.compareTo(th2) == 0, "Straight beats Three of a kind.");
//     th2 = (TestableHand) new Hand();

//     Cardable[] cards3 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.DIAMOND),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(12, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards3);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//     th2 = (TestableHand) new Hand();
//     Cardable[] cards4 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards4);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards5 = {
//       new Card(1, Cardable.Suit.CLUB),
//       new Card(2, Cardable.Suit.CLUB),
//       new Card(12, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards5);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards6 = {
//       new Card(2, Cardable.Suit.CLUB),
//       new Card(3, Cardable.Suit.CLUB),
//       new Card(4, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards6);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards7 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(10, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards7);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards8 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.CLUB),
//       new Card(2, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards8);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//     th2 = (TestableHand) new Hand();
//     Cardable[] cards9 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(4, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards9);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//   }

//   @Test
//   //Four of a kind vs all
//   public void test2() {
//     Cardable[] cards1 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.DIAMOND),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(12, Cardable.Suit.CLUB),
//     };
//     TestableHand th1 = (TestableHand) new Hand();
//     th1.addCards(cards1);

//     TestableHand th2 = (TestableHand) new Hand();
//     Cardable[] cards2 = {
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(10, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards2);
//     assertTrue(th1.compareTo(th2) < 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards3 = {
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards3);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     TestableHand th3 = (TestableHand) new Hand();
//     Cardable[] cards4 = {
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(11, Cardable.Suit.DIAMOND),
//       new Card(12, Cardable.Suit.CLUB),
//     };
//     th3.addCards(cards4);
//     assertTrue(th1.compareTo(th3) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards5 = {
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(11, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards5);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards6 = {
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(0, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards6);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards7 = {
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(2, Cardable.Suit.DIAMOND),
//       new Card(3, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards7);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards8 = {
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(12, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(0, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards8);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//   }

//   @Test
//   // flush vs all
//   public void Test3() {
//     Cardable[] cards1 = {
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(12, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     TestableHand th1 = (TestableHand) new Hand();
//     th1.addCards(cards1);

//     TestableHand th2 = (TestableHand) new Hand();
//     Cardable[] cards8 = {
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(12, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(0, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards8);
//     assertTrue(th1.compareTo(th2) < 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards3 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(5, Cardable.Suit.SPADE),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(0, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards3);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards4 = {
//       new Card(8, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(10, Cardable.Suit.SPADE),
//       new Card(11, Cardable.Suit.DIAMOND),
//       new Card(12, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards4);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//     th2 = (TestableHand) new Hand();
//     Cardable[] cards5 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(10, Cardable.Suit.SPADE),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(0, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards5);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards6 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(9, Cardable.Suit.SPADE),
//       new Card(10, Cardable.Suit.DIAMOND),
//       new Card(0, Cardable.Suit.DIAMOND),
//     };
//     th2.addCards(cards6);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//   }

//   @Test
//   // Straight vs all
//   public void Test4() {
//     Cardable[] cards1 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     TestableHand th1 = (TestableHand) new Hand();
//     th1.addCards(cards1);

//     TestableHand th2 = (TestableHand) new Hand();
//     Cardable[] cards2 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(8, Cardable.Suit.CLUB),
//     };

//     th2.addCards(cards2);
//     assertTrue(th1.compareTo(th2) == 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards3 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(8, Cardable.Suit.CLUB),
//     };

//     th2.addCards(cards3);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards4 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//       new Card(5, Cardable.Suit.SPADE),
//       new Card(8, Cardable.Suit.CLUB),
//     };

//     th2.addCards(cards4);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards5 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//       new Card(5, Cardable.Suit.SPADE),
//       new Card(8, Cardable.Suit.CLUB),
//     };

//     th2.addCards(cards5);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//   }

//   @Test
//   // Straight vs all
//   public void Test5() {
//     Cardable[] cards1 = {
//       new Card(8, Cardable.Suit.DIAMOND),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     TestableHand th1 = (TestableHand) new Hand();
//     th1.addCards(cards1);

//     TestableHand th2 = (TestableHand) new Hand();
//     Cardable[] cards2 = {
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards2);
//     assertTrue(th1.compareTo(th2) < 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards3 = {
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(8, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards3);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards4 = {
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(9, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(5, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards4);

//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards5 = {
//       new Card(9, Cardable.Suit.DIAMOND),
//       new Card(10, Cardable.Suit.CLUB),
//       new Card(8, Cardable.Suit.CLUB),
//       new Card(7, Cardable.Suit.SPADE),
//       new Card(12, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards5);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//   }

//   @Test
//   public void test6() {
//     Cardable[] cards1 = {
//       new Card(5, Cardable.Suit.DIAMOND),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.SPADE),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     TestableHand th1 = (TestableHand) new Hand();
//     th1.addCards(cards1);

//     TestableHand th2 = (TestableHand) new Hand();
//     Cardable[] cards2 = {
//       new Card(7, Cardable.Suit.DIAMOND),
//       new Card(7, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.SPADE),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards2);
//     assertTrue(th1.compareTo(th2) < 0, "Straight beats Three of a kind.");

//     th2 = (TestableHand) new Hand();
//     Cardable[] cards3 = {
//       new Card(7, Cardable.Suit.DIAMOND),
//       new Card(7, Cardable.Suit.CLUB),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.SPADE),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards3);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");
//     th2 = (TestableHand) new Hand();
//     Cardable[] cards4 = {
//       new Card(7, Cardable.Suit.DIAMOND),
//       new Card(4, Cardable.Suit.CLUB),
//       new Card(5, Cardable.Suit.CLUB),
//       new Card(6, Cardable.Suit.SPADE),
//       new Card(9, Cardable.Suit.CLUB),
//     };
//     th2.addCards(cards4);
//     assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");




// 	th1 = (TestableHand) new Hand();
// 	Cardable[] cards5 = {
// 	  new Card(7, Cardable.Suit.DIAMOND),
// 	  new Card(7, Cardable.Suit.CLUB),
// 	  new Card(5, Cardable.Suit.CLUB),
// 	  new Card(6, Cardable.Suit.SPADE),
// 	  new Card(9, Cardable.Suit.CLUB),
// 	};
// 	th1.addCards(cards5);

// 	th2 = (TestableHand) new Hand();
// 	Cardable[] cards6 = {
// 	  new Card(6, Cardable.Suit.DIAMOND),
// 	  new Card(7, Cardable.Suit.CLUB),
// 	  new Card(5, Cardable.Suit.CLUB),
// 	  new Card(6, Cardable.Suit.SPADE),
// 	  new Card(9, Cardable.Suit.CLUB),
// 	};
// 	th2.addCards(cards6);
// 	assertTrue(th1.compareTo(th2) > 0, "Straight beats Three of a kind.");

	

// 	th2 = (TestableHand) new Hand();
// 	Cardable[] cards7 = {
// 	  new Card(6, Cardable.Suit.DIAMOND),
// 	  new Card(7, Cardable.Suit.CLUB),
// 	  new Card(5, Cardable.Suit.CLUB),
// 	  new Card(6, Cardable.Suit.SPADE),
// 	  new Card(9, Cardable.Suit.CLUB),
// 	};
// 	th2.addCards(cards7);
// 	assertTrue(th1.compareTo(th2) < 0, "Straight beats Three of a kind.");

//   }
// }
