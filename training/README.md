# AtMonSat Anomaly Detection Algorithm: training, validation, and testing of deep-learning models

> The project was partly funded by the European Space Agency (ESA) under the Open Space Innovation Platform (OSIP), under which ESA organizes and launches Campaigns and Channels to seek ideas related to space research, otherwise known as ESAIdeas.
> Reference: 
> ESA Contract No.~400134792/21/NL/GLC/my
> ESA activity description No.~I-2020-03332

The atmonsat_model_training.ipynb Jupyter notebook provides code for the training, validation, and testing of various deep-learning model architectures for the anomaly detection algorithm developed within the AtMonSat project. Four different model architectures are defined: an AutoEncoder model, a Convolution Neural Network (CNN)-based model, and two Long Short Term Memory (LSTM)-based models.

For the chosen model architecture:

1) the leave-one-out procedure (i.e., cross-validation) is executed to collect Euclidean and Mahalanobis error samples;

2)  the error thresholds values corresponding to chosen statistical significance level are computed;

2) the chosen model architecture is trained on all training normal datasets;

3) the anomaly detection algorithm with the trained model is run on all abnormal datasets and quantitative performance evaluation metrics are computed.

For quantitative performance evaluation, various metrics are considered:

 - raw and post-processed confusion matrics values, i.e., true positives, false positives, true negstives, and false negatives;
 - precision, recall, and F1-score;
 - ROC curves and Precision-recall curves plots;
 - areas under the ROC and Precision-recall curves.

---

The aux_notebooks directory contains auxiliary notebooks:
 - function_library.ipynb: definitions of various functions used for model trainig, validation, and testing
 - models.ipynb: definitions of different deep-learning model architectures
 - error_thresholds_determination.ipynb: executed in each iteration of the leave-one-out test procedure; trains the chosen model architecture on all but one training normal datasets and performs inference on the excluded normal dataset to collect samples of Euclidean and Mahalanobis errors
 - train_model.ipynb: executed to train the chosen model architecture on all training datasets; the trained model is saved in a .h5 file.
 - detect_anomalies.ipynb: executed on each abnormal dataset to perform inference with the trained model and to compute the Euclidean and Mahalanobis errors. 

The error_thresholds_determination.ipynb, train_model.ipynb, and detect_anomalies.ipynb notebooks in the aux_notebooks directory are not self-contained and can only be run by calls from the atmonsat_model_training.ipynb notebook.