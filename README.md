# quick start
```cpp
		graph_size = 6;

		bmatrix::bmatrix graph(graph_size);


		graph.set(1 - 1, 3 - 1);
		graph.set(3 - 1, 5 - 1);
		graph.set(2 -1 ,3 -1);
		graph.set(2 - 1,4 - 1);
		graph.set(4 - 1,5 - 1);
		graph.set(4 - 1,6 - 1);


		for (int i = 0 ; i < graph_size; i++){
				for (int j = 0; j < graph_size; j++)
						cout << graph.get(i, j) << ", ";
				cout << endl;
		}


```
