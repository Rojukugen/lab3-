#include <gtest.h>
#include "StackLib.h"
#include "Queue.h"


TEST(TStack, can_create_stack)
{
  

  ASSERT_NO_THROW(STACK<int> A;);
}

TEST(TStack, can_add_element)
{
  STACK<int> A;


  ASSERT_NO_THROW(A.push(5););
}

TEST(TStack, can_Extrude_Top_Element)
{
  STACK<int> A;
  A.push(5);
  A.push(6);
  ASSERT_NO_THROW(A.pop());
}

TEST(TStack, can_Extrude_Top_Element_On_stack_zero)
{
  STACK<int> A;

  ASSERT_FALSE(A.pop());
}

TEST(TStack, can_View_Item_At_the_top)
{
  STACK<int> A;
  A.push(5);
  A.push(6);
  ASSERT_NO_THROW(A.Head());
}


TEST(TStack, can_View_Item_At_the_top_stack_zero)
{
  STACK<int> A;
  ASSERT_FALSE(A.Head());
}

TEST(TStack, can_copy)
{
  STACK<int> A;
  A.push(5);
  A.push(6);
  STACK<int> B;
  ASSERT_NO_THROW(B = A;);
}


TEST(TStack, can_copy_NULL)
{
  STACK<int> A;
  STACK<int> B;
  ASSERT_NO_THROW(B = A;);
}




//----


TEST(TQueue, can_create_queue)
{


  ASSERT_NO_THROW(Queue<int> Q1;);
}

TEST(TQueue, can_add_element)
{
  Queue<int> Q1;
  ASSERT_NO_THROW(Q1.push(5););
}

TEST(TQueue, can_View_Top_Element)
{
  Queue<int> A;
  A.push(5);
  A.push(6);
  ASSERT_EQ( A.GetItem() , 5);
}

TEST(TQueue, can_Extrude_Top_Element)
{
  Queue<int> A;
  A.push(5);
  A.push(6);
  A.pop();
  ASSERT_EQ(A.GetItem(), 6);
}

TEST(TQueue, can_Extrude_Top_Element_On_stack_zero)
{
  Queue<int> A;

  ASSERT_FALSE(A.pop());
}


TEST(TQueue, can_copy)
{
  Queue<int> A;
  A.push(5);
  A.push(6);
  Queue<int> B;
  ASSERT_NO_THROW(B = A;);
}


TEST(TQueue, can_copy_NULL)
{
  Queue<int> A;
  Queue<int> B;
  ASSERT_NO_THROW(B = A;);
}
