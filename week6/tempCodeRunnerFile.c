
void testfile()
{

  char *test1 = NULL, *test2 = "", *test3 = "a", *test4 = "yoyo", *test5 = "aeiou", *test6 = "AEIOU", *test7 = " ";

  test_cv(0, test1); //null
  test_cv(0, test2); // ""
  test_cv(1, test3); // "a"
  test_cv(2, test4); //"yoyo"
  test_cv(5, test5); // "aeiou"
  test_cv(5, test6); // "AEIOU"
  test_cv(0, test7); // " "
}