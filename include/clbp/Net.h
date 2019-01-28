#pragma once

#include "Layer.h"


class IcoNet
{
public:
    IcoNet(int _nLayers, int* _nNeurons, int _nInputs);
    ~IcoNet();
    IcoLayer* getLayer(int _layerIndex);
    void initWeights(IcoNeuron::weightInitMethod _wim, IcoNeuron::biasInitMethod _bim);

    void setLearningRate(double _learningRate);
    void setInputs(double* _inputs);
    void propInputs();
    void setError(double _leadError);
    void propError();
    void updateWeights();

    double getOutput(int _neuronIndex);
    double getSumOutput(int _neuronIndex);
    int getnLayers();
    int getnInputs();
    double getWeightDistance();
    double getWeights(int _layerIndex, int _neuronIndex, int _weightIndex);
    int getnNeurons();
    void saveWeights();
    void printNetwork();

private:
    int nLayers=0;
    int nInputs=0;
    int nOutputs=0;
    double* inputs=0;
    IcoLayer** layers=0;
    double learningRate=0;
    double weightDistance=0;
    double weightChange=0;
    int nNeurons;
};