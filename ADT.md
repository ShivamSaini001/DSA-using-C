# Abstract Data Type (ADT)

An Abstract Data Type (ADT) is a mathematical or logical model of a data structure that defines:
- What type of data is stored
- What operations can be performed on the data
But it does not define how the data is implemented internally.

Same ADT can have multiple implementations. 

So,  
<pre>
    ADT = Interface (Data + Operations)  
    Data Structure = Implementation
</pre>

**Abstract:** The word abstract means hiding internal details and showing only important features. In ADT, The user only sees the operations but the internal implementation is hidden.

<pre>
Example:
    If we talk about a Stack ADT, we know operations like:
        - push
        - pop
        - peek
    But ADT does not say whether the stack is implemented using array or linked list.
</pre>


## Types of Abstract Data Types (ADT)
**Abstract Data Types (ADT)** are mainly classified into **two major types** based on how the data elements are organized.  
<pre>
    Abstract Data Types (ADT)
        │
        ├── Linear ADT
        │
        └── Non-Linear ADT
</pre>


### 1. Linear Abstract Data Type:  
A **Linear ADT** is a data type where **elements are arranged in a sequential order**.  
Each element has:  
- one predecessor (previous element)
- one successor (next element)  

Except the first and last elements. So, the data forms a single straight line.





