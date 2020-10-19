#include <gtest.h>
#include "StackLib.h"

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





/* TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> A(MAX_MATRIX_SIZE + 1));
}


TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> M(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> M(5);

  ASSERT_NO_THROW(TMatrix<int> M1(M));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> A(5);
  TMatrix<int> B = A;

  EXPECT_EQ(A, B);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> A(5);
  TMatrix<int> B = A;
  B[0][0] = 1;

  EXPECT_NE(B[0][0], A[0][0]);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int> A(5);
  EXPECT_EQ(A.GetSize(), 5);
}


TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int> A(5);
  A[0][0] = 10;

  EXPECT_EQ(A[0][0], 10);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int> A(5);
  ASSERT_ANY_THROW(A[0][-5] = 10);

}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int> A(5);
  ASSERT_ANY_THROW(A[0][10] = 10);
}



TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix<int> A(5);
  TMatrix<int> B(5);

  ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix<int> A(4);
  TMatrix<int> B(5);

  ASSERT_NO_THROW(A = B);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix<int> A(5);
  TMatrix<int> B(5);

  EXPECT_EQ(A == B, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix<int> A(5);

  EXPECT_EQ(A == A, true);
}

TEST(TMatrix, can_multiplicate)
{
  TMatrix<int> A(5);
  for (int i = 0; i < A.GetSize(); i++)
  {
    for (int j = 0; j < A.GetSize(); j++)
    {
      A[i][j] = 2;
    }
  }
  TMatrix<int> B(5);
  for (int i = 0; i < B.GetSize(); i++)
  {
    for (int j = 0; j < B.GetSize(); j++)
    {
      B[i][j] = 3;
    }
  }

  TMatrix<int> C(5);
  for (int i = 0; i < C.GetSize(); i++)
  {
    for (int j = 0; j < C.GetSize(); j++)
    {
      C[i][j] = 6;
    }
  }

  EXPECT_EQ(A * B, C);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> A(4);
  TMatrix<int> B(5);

  EXPECT_EQ(A == B, false);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix<int> A(5);
  TMatrix<int> RES(10);
  A = 10;
  EXPECT_EQ(A, RES);

}


TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> A(5);
  TMatrix<int> B(6);

  ASSERT_ANY_THROW(A + B);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> A(5);
  TMatrix<int> B(6);

  ASSERT_ANY_THROW(A - B);
}
*/