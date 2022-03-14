int main()
{
    // waiting_list list;
    // list.add(burger(), 10);
    // list.add(pizza(), 10);
    // list.add(stew(), 10);
    queue q;
    q.add(burger(), 10);
    q.add(pizza(), 10);
    q.add(stew(), 10);
    q.add(burger(), 10);
    q.add(pizza(), 10);

    q.remove();
    q.add(pizza(), 10);
    q.print();
    return 0;

    // list.print();
}
