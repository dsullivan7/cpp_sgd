#include <iostream>

class SGD {
    double learning_rate;
    int n_iterations;
    
    public:
        // this method trains the model using the 
        // array of samples X and the labels y
        void fit (double** X, double* y, int n_samples, int n_features);
};

void SGD::fit (double** X, double* y, int n_samples, int n_features) {
    for(int i = 0; i < n_samples; i++){
        for(int j = 0; j < n_features; j++){
            std::cout << X[i][j] << "\t\t";
        }
        std::cout << "\n";
    }
}

int main () {
    SGD sgd;
    int n_samples = 3;
    int n_features = 3;
    double** X;
    X = new double*[n_samples];
    for(int i = 0; i <n_samples; i++){
        X[i] = new double[n_features];
        for(int j = 0; j < n_features; j++){
            X[i][j] = j;
        }
    }
    
    double* y;
    y = new double[n_samples];
    for(int i = 0; i < n_samples; i++){
        y[i] = i;
    }
    
    sgd.fit(X, y, n_samples, n_features);
}

