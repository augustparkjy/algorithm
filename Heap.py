import heapq
heap=[]
heapq.heappush(heap, 4)
heapq.heappush(heap, 1)
heapq.heappush(heap, 7)
heapq.heappush(heap, 3)
print(heap)
#push > O(logN)
print(heapq.heappop(heap))
print(heap)
print(heapq.heappop(heap))
print(heap)
print(heap[0])

heap2 = [4,1,7,3,8,5]
heapq.heapify(heap)
print(heap)
#heapify > O(N)

nums = [4,1,7,3,8,5]
heap3=[]
for num in nums:
    heapq.heappush(heap3, (-num, num))

# print(heap3)
while heap3:
    print(heapq.heappop(heap3)[1])