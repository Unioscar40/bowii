#include <bowii/MathVector.h>
#include <gtest/gtest.h>

TEST(MathVectorTest, CopyConstructor) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    Bowii::MathVector mv2(mv1);

    bool expected = (mv1 == mv2);
    ASSERT_TRUE(expected);
}

TEST(MathVectorTest, AssingOperator) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    Bowii::MathVector mv2;

    mv2 = mv1;

    bool expected = (mv1 == mv2);
    ASSERT_TRUE(expected);
}

TEST(MathVectorTest, EqualOperatorTrue) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    Bowii::MathVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 5; 
    }

    bool expected = (mv1 == mv2);
    ASSERT_TRUE(expected);
}

TEST(MathVectorTest, EqualOperatorFalse) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    Bowii::MathVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 4; 
    }

    bool expected = (mv1 == mv2);
    ASSERT_FALSE(expected);
}

TEST(MathVectorTest, EqualOperatorSizeFalse) {
    size_t tam1{512};
    size_t tam2{300};
    Bowii::MathVector mv1(tam1);
    Bowii::MathVector mv2(tam2);

    bool expected = (mv1 == mv2);
    ASSERT_FALSE(expected);
}

TEST(MathVectorTest, InequalityOperatorTrue) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    Bowii::MathVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 4; 
    }

    bool expected = (mv1 != mv2);
    ASSERT_TRUE(expected);
}

TEST(MathVectorTest, InequalityOperatorSizeTrue) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    Bowii::MathVector mv2(tam+3);

    bool expected = (mv1 != mv2);
    ASSERT_TRUE(expected);
}

TEST(MathVectorTest, InequalityOperatorFalse) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    Bowii::MathVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 5; 
    }

    bool expected = (mv1 != mv2);
    ASSERT_FALSE(expected);
}

TEST(MathVectorTest, MoveConstructor) {
    size_t tam{512};
    Bowii::MathVector mv1(tam);
    bool expected = true;

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
    }

    Bowii::MathVector mv2(std::move(mv1));
    for(size_t i = 0; i < mv2.Size(); i++) {
        if(mv2[i] != 5)
            expected = false;
    }

    ASSERT_TRUE(expected);
}

TEST(MathVectorTest, DotProductRegularTam) {
    size_t tam{512};
    float vector[tam];
    Bowii::MathVector mv1(tam);

    auto expected {0.f};
    auto actual {0.f};

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        vector[i] = 5;
    }

    for(size_t i = 0; i < tam; i++) {
        expected += vector[i] * vector[i];
    }

    actual = Bowii::MathVector::DotProduct(mv1,mv1);
    ASSERT_EQ(expected, actual);
    
}

TEST(MathVectorTest, DotProductIrregularTam) {
    size_t tam{75};
    float vector[tam];
    Bowii::MathVector mv1(tam);

    auto expected {0.f};
    auto actual {0.f};

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        vector[i] = 5;
    }

    for(size_t i = 0; i < tam; i++) {
        expected += vector[i] * vector[i];
    }

    actual = Bowii::MathVector::DotProduct(mv1,mv1);
    ASSERT_EQ(expected, actual);
}

TEST(MathVectorTest, OperatorAddRegularTam) {
    size_t tam {512};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 + mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] + v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(MathVectorTest, OperatorAddIrregularTam) {
    size_t tam {75};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 + mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] + v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(MathVectorTest, OperatorSubRegularTam) {
    size_t tam {512};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(MathVectorTest, OperatorSubIrregularTam) {
    size_t tam {75};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(MathVectorTest, OperatorDivRegularTam) {
    size_t tam {512};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(MathVectorTest, OperatorDivIrregularTam) {
    size_t tam {75};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(MathVectorTest, OperatorMulRegularTam) {
    size_t tam {512};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 * mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] * v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(MathVectorTest, OperatorMulIrregularTam) {
    size_t tam {75};
    Bowii::MathVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::MathVector actual;

    actual = mv1 * mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] * v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}