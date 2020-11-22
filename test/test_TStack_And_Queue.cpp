#include <gtest.h>
#include "StackLib.h"
#include "Queue.h"


TEST(TStack, can_create_stack_with_positive_length) //Ñîçäàíèå ïîëîæèòåëüíîãî
{
  ASSERT_NO_THROW(TStack<int> S_INT(5));
  ASSERT_NO_THROW(TStack<char> S_CHAR(5));

}

TEST(TStack, throws_when_create_stack_with_negative_length) //Îøèáêà ïðè ñîçäàíèè îòðèöàòåëüíîãî
{
  ASSERT_ANY_THROW(TStack<int> S_INT(-5));
  ASSERT_ANY_THROW(TStack<char> S_CHAR(-5));

}

TEST(TStack, can_set_elem) //Äîáàâëåíèå ýëåìåíòà
{
  TStack<int> S(5);

  ASSERT_NO_THROW(S.put(1));

}

TEST(TStack, can_get_size) //Ïîëó÷èòü ðàçìåð
{
  TStack<int> S(5);

  EXPECT_EQ(S.getStackSize(), 5);

}

TEST(TStack, Is_Overflown) //êîíòðîëü ïåðåïîëíåíèÿ
{

  TStack<int> S(4);

  S.put(1);
  S.put(2);
  S.put(3);
  S.put(4);

  ASSERT_NO_THROW();

}

TEST(TStack, IS_Empty) //êîíòðîëü ïóñòîòû
{
  TStack<int> S(4);

  S.put(1);
  S.put(2);
  S.put(3);
  S.put(4);

  ASSERT_NO_THROW();
}


TEST(TStack, can_clear_bit) //Óäàëèòü ýëåìåíò
{
  TStack<int> S(4);

  S.put(0);
  S.put(1);
  S.put(2);
  S.put(3);

  ASSERT_NO_THROW(S.deleteElem());

}


TEST(TStack, get_elem) //Ïîëó÷èòü ýëåìåíò
{
  TStack<int> S(2);

  S.put(0);
  S.put(2);

  EXPECT_EQ(S.Peek(1), 2);

}


TEST(TStack, can_create_copy) //Êîïèðîâàíèå
{
  TStack<int> S1(5);
  S1.put(1);
  TStack<int> S2 = S1;

  EXPECT_EQ(S1.Peek(1), S2.Peek(1));

}

TEST(TStack, throws_when_set_stack_with_too_large_index) //Îøèáêà, ïðè äîáàâëåíèè ëèøíåãî ýëåìåíòà
{
  TStack<int> S(2);

  S.put(1);
  S.put(2);

  ASSERT_ANY_THROW(S.put(3));

}

TEST(TStack, can_get_pointer) //Ïîëó÷èòü óêàçàòåëü
{
  TStack<int> S(2);

  S.put(1);
  S.put(2);

  ASSERT_NO_THROW(S.getPtr());

}

TEST(TStack, can_get_num) //Ïîëó÷èòü íîìåð òåêóùåãî ýëåìåíòà
{
  TStack<int> S(2);

  S.put(1);
  S.put(2);

  EXPECT_EQ(S.getNum(), 2);
}

TEST(TStack, can_get_MIN_elem) //Ïîèñê ìèíèìàëüíîãî ýëåìåíòà
{
  TStack<int> S(3);

  S.put(2);
  S.put(4);
  S.put(6);

  EXPECT_EQ(S.min_elem(), 2);
}

TEST(TStack, can_get_MAX_elem) //Ïîèñêìàêñèìàëüíîãî ýëåìåíòà
{
  TStack<int> S(3);

  S.put(2);
  S.put(4);
  S.put(6);

  EXPECT_EQ(S.max_elem(), 6);
}




//----


TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> qe(3));
}

TEST(TQueue, cant_create_queue_with_null)
{
  ASSERT_ANY_THROW(TQueue<int> qe(0));
}


TEST(TQueue, create_empty_queue)
{
  TQueue<int> qe(3);

  EXPECT_EQ(true, qe.IsEmpty());
}

TEST(TQueue, can_push_if_ok)
{
  TQueue<int> qe(3);

  ASSERT_NO_THROW(qe.Push(3));
}

TEST(TQueue, can_get_elem)
{
  TQueue<int> qe(2);
  qe.Push(4);

  EXPECT_EQ(4, qe.Get());
}

TEST(TQueue, cant_get_if_empty)
{
  TQueue<int> qe(1);

  ASSERT_ANY_THROW(qe.Get());
}

TEST(TQueue, can_copy_queue)
{
  TQueue<int> qe1(2);
  qe1.Push(1);

  ASSERT_NO_THROW(TQueue<int> qe2(qe1));
}

TEST(TQueue, can_assing_queue)
{
  TQueue<int> qe1(2);
  qe1.Push(1);
  TQueue<int> qe2(2);
  qe2 = qe1;

  EXPECT_EQ(1, qe2.Get());
}

TEST(TQueue, test_ring_queue)
{
  TQueue<int> qe(2);
  qe.Push(1);
  qe.Push(2);
  qe.Push(3);
  EXPECT_EQ(2, qe.Get());
}

TEST(TQueue, can_get_Lenght)
{
  TQueue<int> qe(2);

  EXPECT_EQ(2, qe.Length());
}

TEST(TQueue, can_get_MIN_elem)
{
  TQueue<int> qe(3);
  qe.Push(1);
  qe.Push(14);
  qe.Push(7);

  EXPECT_EQ(1, qe.min_elem());
}

TEST(TQueue, can_get_MAX_elem)
{
  TQueue<int> qe(3);
  qe.Push(1);
  qe.Push(14);
  qe.Push(7);

  EXPECT_EQ(14, qe.max_elem());
}

TEST(TQueue, can_get_write_file)
{
  TQueue<int> qe(3);
  qe.Push(1);
  qe.Push(14);
  qe.Push(7);

  ASSERT_NO_THROW(qe.file());
}