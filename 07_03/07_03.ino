#include <math.h>

// Layer 1
const float layer1_weights[][4] = {
  {-2.661358, -0.005710, 3.121311, -6.451425},
  {-2.090339, 1.522780, 3.211208, -6.401955},
};
const float layer1_biases[] = {
  3.708739,
  -0.341909,
  -4.902582,
  2.614123,
};

// Layer 2
const float layer2_weights[][1] = {
  {5.062288},
  {-1.523900},
  {-6.455785},
  {-10.212896},
};
const float layer2_biases[] = {
  1.633715,
};

/*
array([[0.02604198],
       [0.9695868 ],
       [0.9735144 ],
       [0.03164509]], dtype=float32)
*/

float prevOut = 0.0;

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

void loop() {
  int input1 = digitalRead(2);
  int input2 = digitalRead(3);

  float input[2] = {input1, input2};
  float out = 0.0;

  int input_dim = 2;
  int hidden_dense = 4;

  float v2 = 0.0;
  for (int j = 0; j < hidden_dense; j++) {
    float v1 = 0.0;
    for (int i = 0; i < input_dim; i++) {
      v1 += input[i] * layer1_weights[i][j];
    }
    float hidden = sigmoid(v1 + layer1_biases[j]);

    v2 += hidden * layer2_weights[j][0];
  }

  out = sigmoid(v2 + layer2_biases[0]);

  if (prevOut != out) {
    Serial.println(out, 6);
    prevOut = out;
  }

  if (out > 0.5) {
    digitalWrite(LED_BUILTIN, HIGH); 
  } else {
    digitalWrite(LED_BUILTIN, LOW); 
  }

  delay(10);
}
