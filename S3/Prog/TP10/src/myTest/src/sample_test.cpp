#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include "VectorD.hpp"


/////////////////////////////////////////////////////
// constructors

TEST (VectorDConstructor, defaultConstructor) {
	VectorD vec;
	EXPECT_EQ (vec.size(), 0);
}

TEST (VectorDConstructor, copyConstructor) {
	VectorD vec;

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::default_random_engine generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

	// run many times the same test with different values
	for(int i=0; i<100; ++i){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim);
		std::generate(data1.begin(), data1.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
		}
		VectorD v= vec1;

		ASSERT_EQ (v.size(), dim);

		for(size_t i=0; i<dim; ++i){
	    	ASSERT_DOUBLE_EQ (vec1[i], v[i]);
		}
	}
}





/////////////////////////////////////////////////////
// arithmetic

TEST (VectorDArithmetic, plus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::default_random_engine generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

	// run many times the same test with different values
	for(int i=0; i<100; ++i){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim), vec3(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		vec3 = vec1 + vec2;
		ASSERT_EQ (vec3.size(), dim);

		for(size_t i=0; i<dim; ++i){
	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] + data2[i]);
		}
	}
}


TEST (VectorDArithmetic, minus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::default_random_engine generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

	// run many times the same test with different values
	for(int i=0; i<100; ++i){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim), vec3(dim);
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		vec3 = vec1 - vec2;
		ASSERT_EQ (vec3.size(), dim);

		for(size_t i=0; i<dim; ++i){
	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] - data2[i]);
		}
	}
}

TEST (VectorDArithmetic, dot) {

	//random generation

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::default_random_engine generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

	// run many times the same test with different values
	for(int i=0; i<100; ++i){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim), vec3(dim);
		double resDot, resDot2;
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		resDot = vec1.dot(vec2);

		double result = 0.0;
		for(size_t i=0; i<dim; ++i){

				result += vec1[i]*vec2[i];
		}
  	ASSERT_DOUBLE_EQ (resDot, result);


	}
}

TEST (VectorDArithmetic, dotCommutativity) {

	//random generation

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::default_random_engine generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

	// run many times the same test with different values
	for(int i=0; i<100; ++i){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim), vec2(dim), vec3(dim);
		double resDot, resDot2;
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
			vec2[i] = data2[i];
		}

		resDot = vec1.dot(vec2);
		resDot2 = vec2.dot(vec1);

		ASSERT_DOUBLE_EQ (resDot, resDot2);

	}
}

TEST (VectorDArithmetic, dotSelf) {

	//random generation

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::default_random_engine generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

	// run many times the same test with different values
	for(int i=0; i<100; ++i){

		// define a vector dimension
		const size_t dim = uniformIntDistribution(generator);

		// generate random data
		std::vector<double> data1(dim), data2(dim);
		std::generate(data1.begin(), data1.end(), gen);
		std::generate(data2.begin(), data2.end(), gen);

		// build the corresponding VectorD
		VectorD vec1(dim);
		double resDot;
		for(size_t i=0; i<dim; ++i){
			vec1[i] = data1[i];
		}

		resDot = vec1.dot(vec1);

		ASSERT_GE (resDot,0.0);
	}
}

// https://fr.wikipedia.org/wiki/Produit_scalaire
TEST (VectorDArithmetic, dotCosLaw) {

    const size_t maxSize = 1000;  // max size of the tested vectors
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    // run many times the same test with different values
    for(int run=0; run<100; ++run){

        // define a vector dimension
        const size_t dim = uniformIntDistribution(generator);

        // generate random data
        VectorD v1(dim);
        VectorD v2(dim);
        for(size_t i=0; i<dim; ++i){
            v1[i] = gen();
            v2[i] = gen();
        }

        VectorD v3 = v1 - v2;

        ASSERT_LE ( std::abs(v1.dot(v2) - 0.5 * (v1.dot(v1) + v2.dot(v2) - v3.dot(v3))), std::numeric_limits<double>::round_error());
    }
}

TEST (VectorDArithmetic, productVectorSacalar) {

    const size_t maxSize = 1000;  // max size of the tested vectors
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

    // run many times the same test with different values
    for(int j=0; j<100; ++j){

        // define a vector dimension
        const size_t dim = uniformIntDistribution(generator);

        // generate random data
        VectorD v1(dim);
        for(size_t i=0; i<dim; ++i)
            v1[i] = gen();

        VectorD v2(v1);
        const double value = gen();
        v1 = v1 * value;

        for(size_t i=0; i<dim; ++i)
            ASSERT_DOUBLE_EQ (v1[i], v2[i]*value);
    }
}

TEST (VectorDArithmetic, productSacalarVector) {

    const size_t maxSize = 1000;  // max size of the tested vectors
    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
    std::uniform_real_distribution<double> uniformIntDistributionValue(-int(maxSize),maxSize);
    auto gen = [&uniformIntDistributionValue, &generator](){ return uniformIntDistributionValue(generator);};

    // run many times the same test with different values
    for(int j=0; j<100; ++j){

        // define a vector dimension
        const size_t dim = uniformIntDistribution(generator);

        // generate random data
        VectorD v1(dim);
        for(size_t i=0; i<dim; ++i)
            v1[i] = gen();

        VectorD v2(v1);
        const double value = gen();
        v1 = value * v1;

        for(size_t i=0; i<dim; ++i)
            ASSERT_DOUBLE_EQ (v1[i], v2[i]*value);
    }
}


/////////////////////////////////////////////////////
// exception

TEST (VectorDException, loadException) {
	const std::string filename = "filename.txt";
	const std::string expectedException = "VectorD::load: error: can not open file: " + filename;

	// check the exception message
    try{
		VectorD vec;
        vec.load(filename);
    }
    catch( const std::exception &e){
        ASSERT_TRUE( std::string(e.what()).find(expectedException) == 0);
    }
}


TEST (VectorDException, loadExceptionType) {

	// check exception type
	VectorD vec;
	ASSERT_THROW(vec.load("filename.txt"), std::ios_base::failure);
}

TEST (VectorDException, sizePlusExceptionType) {

	// check exception type
	VectorD vec1(5), vec2(10);
	ASSERT_THROW(vec1+vec2, std::length_error);
}


TEST (VectorDException, sizePlusMessage) {


	VectorD vec1(5), vec2(10);
	const std::string expectedException = "VectorD::operator+: operand with incompatible size : " + std::to_string(vec1.size()) + " and " + std::to_string(vec2.size());
	// check exception type

	try{
		vec1+vec2;
	}
	catch( const std::exception &e){
			ASSERT_TRUE( std::string(e.what()).find(expectedException) == 0);
	}
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
