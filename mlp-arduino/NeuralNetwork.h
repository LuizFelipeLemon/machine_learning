#ifndef NEURALNETWORK_LUIZ
#define NEURALNETWORK_LUIZ
#include <vector>
#include "Arduino.h"
#include "Matrix.h"

class NeuralNetwork {
 public:
  NeuralNetwork();
  bool load();

 private:
  bool loadMatrix(int l, int col);
  vector<Matrix<float>> layers;
  vector<Matrix<float>>::iterator ptr;
  int inputs;
  vector<int> units;
  vector<String> activation;
};

NeuralNetwork::NeuralNetwork() { Serial.begin(9600); }
NeuralNetwork::load() {
  if (Serial.available() > 0) {
    int layers = Serial.parseInt();  // number of layers
    inputs = Serial.parseInt();      // number of inputs
    for (int i = 0; i < layers; i++) {
      unitsn = Serial.parseInt();
      units.push_back(unitsn) activationf = Serial.readStringUntil('\n');
      activation.push_back(activationf);
      float weights[inputs][unitsn];
      for (int i = 0; i < inputs; i++) {
        for (int j = 0; j < unitsn; j++) {
          weights[i][j] = Serial.parseFloat();
        }
      }
      layers.push_back(weights);
    }
  }
}
#endif