#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include "../PDS_LAB_5/PDS_LAB_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    std::string bitsetToString(const std::bitset<8>& bset) {
        std::ostringstream oss;
        oss << bset;
        return oss.str();
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        
        TEST_METHOD(TestCartesianProduct)
        {
            std::set<char> A = { 'a', 'b', 'c' };
            std::set<char> B = { 'x', 'y', 'z' };
            std::set<int> C = { 0, 1 };

            std::vector<std::string> expectedResults = {
                "{0, x, x}", "{0, x, y}", "{0, x, z}",
                "{0, y, x}", "{0, y, y}", "{0, y, z}",
                "{0, z, x}", "{0, z, y}", "{0, z, z}",
                "{1, x, x}", "{1, x, y}", "{1, x, z}",
                "{1, y, x}", "{1, y, y}", "{1, y, z}",
                "{1, z, x}", "{1, z, y}", "{1, z, z}"
            };

            std::vector<std::string> actualResults;

            
            for (int c : C) {
                for (char b1 : B) {
                    for (char b2 : B) {
                        std::ostringstream oss;
                        oss << "{" << c << ", " << b1 << ", " << b2 << "}";
                        actualResults.push_back(oss.str());
                    }
                }
            }

            Assert::AreEqual(expectedResults.size(), actualResults.size());
            for (size_t i = 0; i < expectedResults.size(); i++) {
                Assert::AreEqual(expectedResults[i], actualResults[i]);
            }
        }

        
        TEST_METHOD(TestBitwiseOperations)
        {
            std::bitset<8> A("00011011");
            std::bitset<8> B("00100110");

           
            std::bitset<8> expectedDifferenceA = A & ~B; 

           
            std::bitset<8> expectedUnion = A | B;

            
            std::bitset<8> expectedDifferenceB = A & ~B;

            std::bitset<8> expectedSymmetricDifference = A ^ B;

            
            Assert::AreEqual(bitsetToString(expectedDifferenceA), bitsetToString(A & ~B));
            Assert::AreEqual(bitsetToString(expectedUnion), bitsetToString(A | B));
            Assert::AreEqual(bitsetToString(expectedDifferenceB), bitsetToString(A & ~B));
            Assert::AreEqual(bitsetToString(expectedSymmetricDifference), bitsetToString(A ^ B));
        }

        
        TEST_METHOD(TestLogicalOperations)
        {
            bool p = true;
            bool q = false;

           
            bool expectedAnd = p && q;
            bool expectedOr = p || q;  
            bool expectedXor = p ^ q;
            bool expectedImplication = !p || q;  
            bool expectedEquivalence = (p && q) || (!p && !q);  

            Assert::AreEqual(expectedAnd, false);
            Assert::AreEqual(expectedOr, true);
            Assert::AreEqual(expectedXor, true);
            Assert::AreEqual(expectedImplication, false);
            Assert::AreEqual(expectedEquivalence, false);
        }
    };
}
