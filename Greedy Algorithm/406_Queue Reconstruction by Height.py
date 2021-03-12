class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people=sorted(people,key=lambda x:(-x[0],x[1]))
        new_people = list()
        for i in people[0:]:
            new_people.insert(i[1],i)
        return new_people
