def merge(nums1, nums2):
    arr3 = []
    p1, p2 = 0, 0
    while p1 < len(nums1) and p2 < len(nums2):
        if nums1[p1] < nums2[p2]:
            arr3.append(nums1[p1])
            p1 += 1
        else:
            arr3.append(nums2[p2])
            p2 += 1
    arr3 += nums1[p1:]
    arr3 += nums2[p2:]
    return arr3


print(merge([1, 3, 7, 8, 9, 11], [10, 12, 15, 16, 18]))
