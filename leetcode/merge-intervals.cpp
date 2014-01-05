static bool compareFunc(const Interval &a, const Interval &b){
    return a.start<b.start;
}
vector<Interval> merge(vector<Interval> &intervals){
    std::vector<Interval> mergedIntervals;
    if (intervals.size()==0) return mergedIntervals;
    std::sort(intervals.begin(),intervals.end(),Solution::compareFunc);
    mergedIntervals.push_back(intervals[0]);
    for (int i=1;i<intervals.size();i++)
        if (intervals[i].start<=mergedIntervals.back().end)
            mergedIntervals.back().end=max(intervals[i].end,mergedIntervals.back().end);
        else mergedIntervals.push_back(intervals[i]);
    return mergedIntervals;
}