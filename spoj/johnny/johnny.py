# This program uses Karman-Karp algorithm

class Parcel:
    def __init__(self, weight, id):
        self.weight = weight
        self.id = id

class Queue:
    def __init__(self):
        self.queue = []
        self.size = 0

    def push(self, parcel):
        self.size += 1
        self.queue.insert(0, parcel)

    def pop(self):
        self.size -= 1
        return self.queue.pop()

    def __len__(self):
        return self.size
    
    def sort(self, reverse=False):
        self.queue.sort(reverse=reverse)


parcels = []
weights = Queue()

n = int(input())

for i in range(n):
    parcel = Parcel(int(input()), i + 1)
    parcels.append(parcel)

parcels = sorted(parcels, key=lambda x: x.weight, reverse=True)

for parcel in parcels:
    weights.push(parcel.weight)

largests = []

while len(weights) > 1:
    largest_weight = weights.pop()
    second_largest_weight = weights.pop()
    largests.append((largest_weight, second_largest_weight))
    difference = abs(largest_weight - second_largest_weight)
    weights.push(difference)
    weights.sort()

difference = abs(weights.pop())

left_hand = [difference]
left_sum = difference
right_hand = []
right_sum = 0

while len(largests) > 0:
    largest_1, largest_2 = largests.pop()
    difference = abs(largest_1 - largest_2)

    if difference in left_hand:
        left_hand.remove(difference)
        left_sum -= difference
    elif difference in right_hand:
        right_hand.remove(difference)
        right_sum -= difference

    if left_sum < right_sum:
        left_hand.append(largest_1)
        left_sum += largest_1
        right_hand.append(largest_2)
        right_sum += largest_2
    else:
        left_hand.append(largest_2)
        left_sum += largest_2
        right_hand.append(largest_1)
        right_sum += largest_1


right_hand_result = []
for parcel in parcels:
    if parcel.weight in right_hand:
        right_hand_result.append(parcel.id)

print("\n".join(map(str, right_hand_result)))
