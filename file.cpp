#include <iostream>
#include <cmath>

class cFunction {
public:
      virtual  double evaluate(double x)  const  = 0 ;
};



class QuadraticFunction : public cFunction {
private:
    double a, b, c;

public:
    QuadraticFunction(double a, double b, double c) : a(a), b(b), c(c) {}

    double evaluate(double x) const  override {
        std::cout << "QuadraticFunction evaluate called" << std::endl;
        return a * x * x + b * x + c;
    }

    ~QuadraticFunction() {
        
        std::cout << "QuadraticFunction destructor called" << std::endl;
        //delete this;
    }
};

class ExponentialFunction : public cFunction {
    private:
        double a;
    public:
        ExponentialFunction(double a) : a(a) {}
    
    double evaluate(double x) const override  {
        std::cout << "ExponentialFunction evaluate called" << std::endl;
        return a * std::exp(x);
    }

    ~ExponentialFunction() {
        std::cout << "ExponentialFunction destructor called" << std::endl;
        //delete this;  
    }
};

class TrigonometricFunction : public cFunction {
    
    private:
        double a,b;
    public:
        TrigonometricFunction(double a, double b) : a(a), b(b) {}

    double evaluate(double x) const override {
        std::cout << "TrigonometricFunction evaluate called" << std::endl;
        return a * std::sin(x) + b * std::cos(x);
    }
    ~TrigonometricFunction() {
        std::cout << "TrigonometricFunction destructor called" << std::endl;
        //delete this;
    }
};





    static void generateArt(const  cFunction* object, double minX, double maxX, int numPoints)  {
        double step = (maxX - minX) / numPoints;

        for (double x = minX; x <= maxX; x += step) {
            double y = object->evaluate(x);
            int numStars = static_cast<int>(y);

            for (int i = 0; i < numStars; i++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    };


int main() {
    // Create a QuadraticFunction object
    cFunction* quadraticFunction = new QuadraticFunction(1.0, -2.0, 1.0);
    
    //cFunction exp = static_cast<ExponentialFunction>(3);
    cFunction* exponentialFunction = new ExponentialFunction(3);

    cFunction* trigonometricFunction = new TrigonometricFunction(3,-1);
   

   
    generateArt(quadraticFunction, -10.0, 10.0, 50);
    //generateArt(&exp, -10.0, 10.0, 50);
    generateArt(exponentialFunction, -10.0, 10.0, 50);
    // Clean up the memory
    delete quadraticFunction;
    //delete &exp;
    delete exponentialFunction;

    return 0;
}



