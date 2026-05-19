def check_legs(s):
    return "leg" in s

def check_rest(s):
    return "rest" in s

def main():
    n = int(input().strip())
    exercises = []
    
    for _ in range(n):
        s = input().strip()
        if check_rest(s):
            exercises.append(0)  # Rest day (face)
        elif check_legs(s):
            exercises.append(1)  # Leg day
        else:
            exercises.append(2)  # Arm day

    # Using Unicode code points instead of direct emojis
    emojis = {
        0: "\U0001F600",  # Grinning Face
        1: "\U0001F9B5",  # Leg
        2: "\U0001F4AA"   #  Biceps (Arm)
    }

    days_in_month = 31

    for week in range(1, 6):
        print(week, end=" ")
        for day in range(7):
            current_day = (week - 1) * 7 + day
            if current_day >= days_in_month:
                break  # Stop after 31 days
            print(emojis[exercises[current_day % n]], end=" ")
        print()  # New line after each week

if __name__ == "__main__":
    main()
