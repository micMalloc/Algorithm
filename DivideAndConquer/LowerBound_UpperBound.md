# Lower Bound & Upper Bound

> ***Lower Bound*** 와 ***Upper Bound*** 는 이분 탐색으로부터 파생된 알고리즘이다. </br>
>
> *Binary Search*(이분 탐색) '원하는 값 k를 찾는 과정'</br>
>
> **_Lower Bound_**  '원하는 값 <u>*k 이상*</u> 이 처음 나오는 ***'위치\'*** 를 찾는 과정' 이며 즉, 어떠한 값의 하한선을 의미한다.</br>
>
> ***Upper Bound***  '원하는 값 <u>*k를 초과*</u> 한 값이 청므 나오는 '***위치\'*** 를 찾는 과정' 이며, 어떠한 값의 상한선을 의미한다.

</br></br>

## Implementation (C++)

### Lower Bound

```c++
/* Loop Version */
int lower_bound (const int arr[], const int START, const int END, const int K) {
		int left = START;
  	int right = END:
  	int mid;
  
  	while (left <= right) {
    		mid = (left + right) >> 1;
      	if (arr[mid] >= K) {
          	right = mid;
        }
      	else {
          	left = mid + 1;
        }
		}
  
  	return right;
}
```

</br>

### Upper Bound

```c++
/* Loop Version */
int upper_bound (const int arr[], const int START, const int END, const int K) {
		int left = START;
  	int right = END:
  	int mid;
  
  	while (left <= right) {
    		mid = (left + right) >> 1;
      	if (arr[mid] > K) {
          	right = mid;
        }
      	else {
          	left = mid + 1;
        }
		}
  
  	return right;
}
```

</br>