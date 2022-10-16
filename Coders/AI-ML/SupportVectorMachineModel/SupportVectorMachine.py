import pandas as pd
from sklearn.datasets import load_iris
iris=load_iris()
df = pd.DataFrame(iris.data,columns=iris.feature_names)
df['target']=iris.target
x=df.drop('target',axis="columns")
y=df.target   
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2)
from sklearn.svm import SVC 
model=SVC()
model.fit(x_train,y_train)
model.score(x_test,y_test)
