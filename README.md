*This project has been created as part of the 42 curriculum by melschmi && mdourdoi*

# Description

The scope of this project is to sort a list of integer.

For that, we consider this list as a stack, and we get a set of operation and another empty stack where we can put elements of the given stack with said operations.

A valid stack is made of a list of integers with no duplicate.

# Instructions

This project contains a Makefile with 2 rules :

## all (make)

Creates the push_swap binary.

You must pass it 2 families of arguments, in this order : 

#### flags : 

--simple, --medium, --complex or --adaptive for the type of algorithm you want to use. You can only chose one.

--bench to display more details like the number of each operations, the total of operations, the disorder metric amd the strategy used.

You can pass the flags in any order. By default, the adaptive method is selected and the bench is not displayed.

#### stack :

A list of integers with no duplicate. Since we had multiple different examples and we didn't want to miss out, we decided that you can either put each integer separated with one or more space, put the whole stack as a single string composed of integers separated with one or more spaces, or both.

TLDR : these examples have the same output

<pre>
./push_swap 5 4 9 8 6 0

./push_swap "5 4 9 8 6 0"

./push_swap 5 4 9 "8 6 0"

./push_swap 5 4 9 8 6 0 "   "

./push_swap 5 4 9                   8 6 0

ARG="5 4 9 8 6 0"; ./push_swap $ARG
</pre>

## checker (make checker)

Creates the checker binary.

You must pipe it with the push_swap binary and give it the same stack. For example : 

./push_swap 5 4 9 8 6 0 | ./checker 5 4 9 8 6 0

For the same reasons, you can input the stack the same way as above.

# Resources

Selection sort : https://en.wikipedia.org/wiki/Selection_sort

Bucket sort : https://en.wikipedia.org/wiki/Bucket_sort

Radix sort : https://en.wikipedia.org/wiki/Radix_sort && kapinarc's brain

Usage of AI : To debug the bucket sort because we didn't see a tiny detail that made us switch to the next bucket too soon.

# In depth explaination of each algorithm (trigger warning : maths)

In each scenario, we used a function called "ft_select_rot" (ft_select_rot_a and ft_select_rot_b since we didn´t have enough authorize variable to make just one, but they do essentialy the same except they print "ra" and "rra", or "rb" and "rrb", so let's consider it as a single function). It takes a stack and 2 positions and optimize wether it's more optimized in terms of push_swap operation to rotate to go to the first, or reverse_rotate to go to the other.

Essentially, it was used to check wether its better to rotate or reverse rotate to go to an element (n rotation or len - n reverse rotations), but in the second algorithm when we fill bucket it was used in another way.

For the justifications :

- Selection sort for the simple method is because it is the most naive way we found to implement the O(n²)

- Bucket sort for the medium method is because it is very intuitive, since we have 2 stacks, to separate buckets

- Radix sort for the complex algorithm because we wanted to see what bitwise operations are, and it seemed very easy to implement

Before each sort, we calculate the metric disorder as asked. If the adaptive method is selected, it select the correct way according to it ( O(n²) iif disorder < 0.2, O(n*sqrt(n)) if 0.2 ≤ disorder < 0.5 and O(nlog(n)) otherwise).

## Simple : Selection sort

We search each time in the stack A the minimum with ft_select_rot and push it in B until the stack A is empty. It gives us a stack B that is sorted in reverse.

Worst case scenario : We need to rotate the full stack each time (most likely never happens), so the number of operations is :

 ![sum-full](https://latex.codecogs.com/svg.image?\sum_{k=1}^{n}k=\frac{n(n+1)}{2}=\frac{1}{2}n^2+\frac{1}{2}n)

We then push this reverse-sorted stack in A, giving us a correctly-sorted stack A. It takes exactly n operations.

In the end, we have in term of push_swap operations :

 ![latex](https://latex.codecogs.com/svg.image?\frac{1}{2}n^2+\frac{1}{2}n+n=\frac{1}{2}n^2+\frac{3}{2}n=O(n^2))

## Medium : Bucket sort

We (virtualy) cut the initial stack into several interval of size k (we will transform this k later into ![latex](https://latex.codecogs.com/svg.image?\sqrt{n})). The first bucket contains the k first elements, the second the k next etc ...

#### Step 1

We push each bucket one by one in A, starting with the first one (with the lower elements). For this, we scan the stack to get the one closest to the top and the one closest to the bottom, then with ft_select_rot we select the one with the least cost to get and rotate or reverse_rotate then push it, then repeat until the bucket is fully pushed.

We repeat this step until all the buckets are pushed, so we do this k times.

At the end of the bucket m, we did at most ![latex](https://latex.codecogs.com/svg.image?n-(m-1)*k+k=n-mk) operations (n-m*k is the size of A and the number of rotation in the worst case scenario, k is the number of pushes)

When A is fully pushed, we did in terms of operations :

![sum-full](https://latex.codecogs.com/svg.image?\sum_{m=1}^{\frac{n}{k}}n-mk=\frac{n}{k}*n-k\sum_{m=1}^{\frac{n}{k}}m=\frac{n^2}{k}-k*\frac{\frac{n}{k}*(\frac{n}{k}-1)}{2}=\frac{n^2}{k}-\frac{n*(\frac{n}{k}-1)}{2}=\frac{n^2}{k}-\frac{n^2-k}{2k}=\frac{n^2-k}{2k})

If now we take ![latex](https://latex.codecogs.com/svg.image?k=\sqrt{n}) (and that's what we do and what we will do now):

![latex](https://latex.codecogs.com/svg.image?\frac{n^2-k}{2k}=\frac{n^2-\sqrt{n}}{2\sqrt{n}}=\frac{n\sqrt{n}-1}{2})

#### Step 2

For each bucket, we search the maximum of the stack B, which is always on the top bucket so in the first ![latex](https://latex.codecogs.com/svg.image?\sqrt{n}) elements (with rotations, they may go to the end of the stack, that's why we use ft_select_rot, and maybe it will gain us some operations with the last bucket as well).

Each time, we do at most in terms of push_swap operations :

![latex](https://latex.codecogs.com/svg.image?\sqrt{n}+1)

So for each bucket, we do :

![latex](https://latex.codecogs.com/svg.image?\sqrt{n}(\sqrt{n}+1)=n)

We have ![latex](https://latex.codecogs.com/svg.image?\sqrt{n}) buckets, so after we did all the bucket, we did in term of operations : 

![latex](https://latex.codecogs.com/svg.image?\sqrt{n}*n)

#### Final count

In the end, we did :

![latex](https://latex.codecogs.com/svg.image?\sqrt{n}*n+\frac{n\sqrt{n}-1}{2}=\frac{3}{2}n\sqrt{n}-\frac{1}{2}=O(n\sqrt{n}))

I'm sorry.

## Complex : Radix sort

Prerequisite : We need to get the final index of each element (0 for the top of the stack, 1 for the second, ..., len - 1 for the last). We have a function called set_index for that.

We will check every bit of the index of each element in A. For each bit, if it is 1 we push it to B, else we rotate A and repeat until we've checked each element, then we push everything back to A and scan for the next bit.

#### Optimization :

- We do not check the max bit need to scan, we rather go for the full 32 bits (since we work with ints) and check after re-pushing everything into A if the list is sorted.

- Instead of checking every element, we pre-check how many elements we need to push to B. When there is no left, instead of rotating to check every one of them, we check with ft_select_rot if it's better to rotate as expected or reverse rotate to go to the same position and preserve the order in the stack (which is central in a radix sort).

#### Complexity

Worst case scenario : We will go to the last step that scan the leftmost bit.

We go to each element of the stack each time, so we do n operations at most for each step, so in total we do n*[the number of bits needed to represent the biggest index in the stack]. Let's calculate that.

In binary, a number represented on b bits is always lower than 2^b, so if n is the number of elements (and n-1 the biggest index) we need the lowest b where :

![latex](https://latex.codecogs.com/svg.image?2^b{\le}n-1{\iff}b{\le}log_{2}(n-1))

And then

![latex](https://latex.codecogs.com/svg.image?log_{2}(n-1)=\frac{log(n-1)}{log(2)})

The lowest b is exactly

![latex](https://latex.codecogs.com/svg.image?\lceil\frac{log(n-1)}{log(2)}\rceil)

So in total, since log is strictly increasing and 1/log(2) is roughly 1.44, we do in term of push_swap operations :

![latex](https://latex.codecogs.com/svg.image?n*\lceil\frac{log(n-1)}{log(2)}\rceil{\le}1.45*nlog(n)=O(nlog(n)))