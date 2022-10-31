from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier

# Importing DataSet IRIS
IRIS = datasets.load_iris()

# About Data
print(IRIS.DESCR)

print("Length of DataSet",len(IRIS.data),len(IRIS.target))
print(IRIS.keys())

X_train, X_test, Y_train, Y_test = train_test_split(
    IRIS.data, IRIS.target, test_size=0.2)

model1 = KNeighborsClassifier(n_neighbors=1)

model1.fit(X_train,Y_train)

model1.predict(X_test)

model1.score(X_test,Y_test)

model2 = KNeighborsClassifier(n_neighbors=3)

model2.fit(X_train,Y_train)

model2.predict(X_test)

model2.score(X_test, Y_test)

Y_train
