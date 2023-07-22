#include <bowii/BVector.h>
#include <gtest/gtest.h>
#include <algorithm>

TEST(BVectorTest, CopyConstructor) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    Bowii::BVector mv2(mv1);

    bool expected = (mv1 == mv2);
    ASSERT_TRUE(expected);
}

TEST(BVectorTest, AssingOperator) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    Bowii::BVector mv2;

    mv2 = mv1;

    bool expected = (mv1 == mv2);
    ASSERT_TRUE(expected);
}

TEST(BVectorTest, EqualOperatorTrue) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    Bowii::BVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 5; 
    }

    bool expected = (mv1 == mv2);
    ASSERT_TRUE(expected);
}

TEST(BVectorTest, EqualOperatorFalse) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    Bowii::BVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 4; 
    }

    bool expected = (mv1 == mv2);
    ASSERT_FALSE(expected);
}

TEST(BVectorTest, EqualOperatorSizeFalse) {
    size_t tam1{512};
    size_t tam2{300};
    Bowii::BVector mv1(tam1);
    Bowii::BVector mv2(tam2);

    bool expected = (mv1 == mv2);
    ASSERT_FALSE(expected);
}

TEST(BVectorTest, InequalityOperatorTrue) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    Bowii::BVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 4; 
    }

    bool expected = (mv1 != mv2);
    ASSERT_TRUE(expected);
}

TEST(BVectorTest, InequalityOperatorSizeTrue) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    Bowii::BVector mv2(tam+3);

    bool expected = (mv1 != mv2);
    ASSERT_TRUE(expected);
}

TEST(BVectorTest, InequalityOperatorFalse) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    Bowii::BVector mv2(tam);

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        mv2[i] = 5; 
    }

    bool expected = (mv1 != mv2);
    ASSERT_FALSE(expected);
}

TEST(BVectorTest, MoveConstructor) {
    size_t tam{512};
    Bowii::BVector mv1(tam);
    bool expected = true;

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
    }

    Bowii::BVector mv2(std::move(mv1));
    for(size_t i = 0; i < mv2.Size(); i++) {
        if(mv2[i] != 5)
            expected = false;
    }

    ASSERT_TRUE(expected);
}

TEST(BVectorTest, DotProductRegularTam) {
    size_t tam{512};
    float vector[tam];
    Bowii::BVector mv1(tam);

    auto expected {0.f};
    auto actual {0.f};

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        vector[i] = 5;
    }

    for(size_t i = 0; i < tam; i++) {
        expected += vector[i] * vector[i];
    }

    actual = Bowii::BVector::DotProduct(mv1,mv1);
    ASSERT_EQ(expected, actual);
    
}

TEST(BVectorTest, DotProductIrregularTam) {
    size_t tam{75};
    float vector[tam];
    Bowii::BVector mv1(tam);

    auto expected {0.f};
    auto actual {0.f};

    for(size_t i = 0; i < mv1.Size(); i++) {
        mv1[i] = 5;
        vector[i] = 5;
    }

    for(size_t i = 0; i < tam; i++) {
        expected += vector[i] * vector[i];
    }

    actual = Bowii::BVector::DotProduct(mv1,mv1);
    ASSERT_EQ(expected, actual);
}

TEST(BVectorTest, OperatorAddRegularTam) {
    size_t tam {512};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 + mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] + v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, OperatorAddIrregularTam) {
    size_t tam {75};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 + mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] + v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, OperatorSubRegularTam) {
    size_t tam {512};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, OperatorSubIrregularTam) {
    size_t tam {75};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, OperatorDivRegularTam) {
    size_t tam {512};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, OperatorDivIrregularTam) {
    size_t tam {75};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 - mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] - v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, OperatorMulRegularTam) {
    size_t tam {512};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 * mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] * v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, OperatorMulIrregularTam) {
    size_t tam {75};
    Bowii::BVector mv1(tam); 
    float v[tam];
    float expected[tam];
    bool sol = true;

    for(unsigned i = 0; i < tam ; i++) {
        mv1[i] = 5;
        v[i] = 5;
    }
    Bowii::BVector actual;

    actual = mv1 * mv1;    

    for(size_t i = 0; i < tam; i++) {
        expected[i] = v[i] * v[i];
        if(expected[i] != actual[i])
            sol = false;
    }

    ASSERT_TRUE(sol);

}

TEST(BVectorTest, SizeOk) {
    size_t tam{64};
    Bowii::BVector mv(tam);

    ASSERT_EQ(tam,mv.Size());

}

TEST(BVectorTest, MaxElemRegularTam) {
    size_t tam{512};
    Bowii::BVector mv(tam);
    for(size_t i = 0; i < tam; i++) {
        mv[i] = i;
    }
    
    float expected = 511;
    ASSERT_EQ(expected,Bowii::BVector::MaxElem(mv));
}

TEST(BVectorTest, MaxElemIrregularTam) {
    size_t tam{517};
    Bowii::BVector mv(tam);
    for(size_t i = 0; i < tam; i++) {
        mv[i] = i;
    }
    float expected = 516;
    ASSERT_EQ(expected,Bowii::BVector::MaxElem(mv));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}