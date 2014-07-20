#include "loss_functions.cpp"
#include <iostream>

class SGD {
    double learning_rate;
    int n_iterations;
    
    public:
        // this method trains the model using the 
        // array of samples X and the labels y
        void fit (double** X, double* y, int n_samples, int n_features, double learning_rate);
};

void SGD::fit (double** X, double* y, int n_samples, int n_features, double learning_rate) {
    double weights[n_features];
    double gradient[n_features];
    double p;
    Hinge hinge(1.0);

    // iterate through each sample in X
    for(int i = 0; i < n_samples; i++){
        p = 0;   
        
        // itereate once to compute the gradient for each entry
        for(int j = 0; j < n_features; j++){
            
            // compute the dot product of this sample and the weights
            // to get the evaluation at this point
            p = p + X[i][j] * weights[j];

            // compute the gradient by computing the derivative of
            // the loss for this sample
            gradient[j] = hinge.dloss(p, y[j]) * X[i][j];
        }
        
        // iterate again to update the weights
        for(int j = 0; j < n_features; j++){
            weights[j] = weights[j] - learning_rate * gradient[j];        
        }
    }

    for(int j = 0; j < n_features; j++){
        std::cout << weights[j] << "  ";
    }
}

int main () {
    SGD sgd;
    
    int n_samples = 100;
    int n_features = 4;
    double learning_rate = .01;
    double** X;
    X = new double*[n_samples];
    
    for(int i = 0; i <n_samples; i++){
        X[i] = new double[n_features];
        for(int j = 0; j < n_features; j++){
            X[i][j] = i;
        }
    }
    
    double* y;
    y = new double[n_samples];
    
    for(int i = 0; i < n_samples; i++){
        y[i] = i;
    }
    
    sgd.fit(X, y, n_samples, n_features, learning_rate);
}

