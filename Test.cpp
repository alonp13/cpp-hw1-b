#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b and f") {
    string text = "xxx happy yyyf";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    /* Add more checks here */
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "habfy") == string("happy"));
    CHECK(find(text, "hafby") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "yyyb") == string("yyyf"));
    CHECK(find(text, "yyyp") == string("yyyf"));

}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
    CHECK(find(text, "HAppi") == string("Happi"));
    CHECK(find(text, "HaApi") == string("Happi"));
    CHECK(find(text, "haPpi") == string("Happi"));
    CHECK(find(text, "haPPi") == string("Happi"));
    CHECK(find(text, "hapPI") == string("Happi"));
    CHECK(find(text, "HappI") == string("Happi"));
   
}

/* Add more test cases here */
TEST_CASE("Test replacement of c and k and q") {
    string text = "clock queue";
    CHECK(find(text,"clock") == string("clock"));
    CHECK(find(text,"klock") == string("clock"));
    CHECK(find(text,"qlock") == string("clock"));
    CHECK(find(text,"clokk") == string("clock"));
    CHECK(find(text,"cloqk") == string("clock"));
    CHECK(find(text,"clocc") == string("clock"));
    CHECK(find(text,"clocq") == string("clock"));
    CHECK(find(text,"queue") == string("queue"));
    CHECK(find(text,"cueue") == string("queue"));
    CHECK(find(text,"kueue") == string("queue"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "volkswagen VMWare wow";
    CHECK(find(text,"volkswagen") == string("volkswagen"));
    CHECK(find(text,"wolkswagen") == string("volkswagen"));
    CHECK(find(text,"volksvagen") == string("volkswagen"));
    CHECK(find(text,"wolksvagen") == string("volkswagen"));
    CHECK(find(text,"VMWare") == string("VMWare"));
    CHECK(find(text,"WMWare") == string("VMWare"));
    CHECK(find(text,"VMVare") == string("VMWare"));
    CHECK(find(text,"WMVare") == string("VMWare"));
    CHECK(find(text,"wow") == string("wow"));
    CHECK(find(text,"wov") == string("wow"));
    CHECK(find(text,"vow") == string("wow"));
    CHECK(find(text,"vov") == string("wow"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "ganja juggle";
    CHECK(find(text,"ganja") == string("ganja"));
    CHECK(find(text,"janja") == string("ganja"));
    CHECK(find(text,"ganga") == string("ganja"));
    CHECK(find(text,"janga") == string("ganja"));
    CHECK(find(text,"jujjle") == string("juggle"));
    CHECK(find(text,"jujgle") == string("juggle"));
    CHECK(find(text,"jugjle") == string("juggle"));
    CHECK(find(text,"gujjle") == string("juggle"));
    CHECK(find(text,"gujgle") == string("juggle"));
    CHECK(find(text,"gugjle") == string("juggle"));   
    CHECK(find(text,"guggle") == string("juggle"));   
}

TEST_CASE("Test replacement of s and z") {
    string text = "size zoosman suzi";
    CHECK(find(text,"sise") == string("size"));
    CHECK(find(text,"size") == string("size"));
    CHECK(find(text,"zise") == string("size"));
    CHECK(find(text,"zize") == string("size"));
    CHECK(find(text,"soosman") == string("zoosman"));
    CHECK(find(text,"soozman") == string("zoosman"));
    CHECK(find(text,"zoosman") == string("zoosman"));
    CHECK(find(text,"zoozman") == string("zoosman"));
    CHECK(find(text,"susi") == string("suzi"));
    CHECK(find(text,"suzi") == string("suzi"));
    CHECK(find(text,"zusi") == string("suzi"));
    CHECK(find(text,"zuzi") == string("suzi"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "dont tend dot";
    CHECK(find(text,"dond") == string("dont"));
    CHECK(find(text,"dont") == string("dont"));
    CHECK(find(text,"tond") == string("dont"));
    CHECK(find(text,"tont") == string("dont"));
    CHECK(find(text,"dend") == string("tend"));
    CHECK(find(text,"dent") == string("tend"));
    CHECK(find(text,"tend") == string("tend"));
    CHECK(find(text,"tent") == string("tend"));
    CHECK(find(text,"dod") == string("dot"));
    CHECK(find(text,"dot") == string("dot"));
    CHECK(find(text,"tod") == string("dot"));
    CHECK(find(text,"tot") == string("dot"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "ouch occured you";
    CHECK(find(text,"ooch") == string("ouch"));
    CHECK(find(text,"ouch") == string("ouch"));
    CHECK(find(text,"uoch") == string("ouch"));
    CHECK(find(text,"uuch") == string("ouch"));
    CHECK(find(text,"occored") == string("occured"));
    CHECK(find(text,"occured") == string("occured"));
    CHECK(find(text,"uccored") == string("occured"));
    CHECK(find(text,"uccured") == string("occured"));
    CHECK(find(text,"yoo") == string("you"));
    CHECK(find(text,"you") == string("you"));
    CHECK(find(text,"yuo") == string("you"));
    CHECK(find(text,"yuu") == string("you"));
}

TEST_CASE("Test replacement of y and i") {
    string text = "yield yei Itay";
    CHECK(find(text,"yyeld") == string("yield"));
    CHECK(find(text,"yield") == string("yield"));
    CHECK(find(text,"iyeld") == string("yield"));
    CHECK(find(text,"iield") == string("yield"));
    CHECK(find(text,"yey") == string("yei"));
    CHECK(find(text,"yei") == string("yei"));
    CHECK(find(text,"iey") == string("yei"));
    CHECK(find(text,"iei") == string("yei"));
    CHECK(find(text,"ytay") == string("Itay"));
    CHECK(find(text,"Ytai") == string("Itay"));
    CHECK(find(text,"itay") == string("Itay"));
    CHECK(find(text,"ItaI") == string("Itay"));
}