def solution(bridge_length, weight, truck_weights):
    answer = 0
    truck = [0] * bridge_length
    
    while truck:
        answer += 1
        truck.pop(0)
        if truck_weights:
            if sum(truck) + truck_weights[0] <= weight:
                truck.append(truck_weights.pop(0))
            else:
                truck.append(0)
    return answer

print(solution(2, 10, [7,4,5,6]))