# Project 4 - FileDependency_GraphAnalyzer

### Features:
1. Find the packages in a given directory. A package is a pair of .cpp and .h files with the same name.
2. Each package constitutes a vertex in our dependency graph. We are interested in only analyzing the #include statements. 
   You should assume that #include statements are always on top of each file.
   This means that you do not have to read the entire file or develop a complex parser.
3. Construct an adjacency matrix to represent this graph. 
4. List the cycles and strong components.
5. List the names of vertices with DFS.
6. Show the topological sort of the vertices.  
