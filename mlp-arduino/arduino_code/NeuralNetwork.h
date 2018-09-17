#ifndef NEURALNETWORK_LUIZ
#define NEURALNETWORK_LUIZ
#include "vector.h"
#include "Arduino.h"
#include "Matrix.h"

class NeuralNetwork {
  public:
    NeuralNetwork();
    bool load();

  private:
    //bool loadMatrix(int l, int col);
    vector<Matrix<float>> layers;
    //vector<Matrix<float>>::iterator ptr;
    int inputs;
    int layersN, inputN;
    vector<int> units;
    vector<String> activation;
};

NeuralNetwork::NeuralNetwork() {




}


bool NeuralNetwork::load() {

  while (Serial.available() <= 0) {
    Serial.println("called");
  }
  if (Serial.available() > 0) {
    layersN = Serial.parseInt();  // number of layers
    Serial.print("The number of layers is: ");
    Serial.println(layersN);
    //layers = vector<Matrix<float>>(layersN);
    inputN = Serial.parseInt();
    Serial.print("And the number of inputs is: ");
    Serial.println(inputN);
    units.push_back(inputN);

    for (int i = 0; i < layersN; i++) {
      int unitsN = Serial.parseInt();
      Serial.print("And the number of unitsN is: ");
      Serial.println(unitsN);
      String activationf = Serial.readStringUntil(' ');
      Serial.print("And the activationf is: ");
      Serial.println(activationf);
      activation.push_back(activationf);
      float weights[inputN][unitsN];
      for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < unitsN; j++) {
          weights[i][j] = Serial.parseFloat();
        }
      }
      Matrix<float> A(1,3,weights);
      A.show();
//      layers.push_back(weights);
      inputN = unitsN;
    }
  }
}
#endif
