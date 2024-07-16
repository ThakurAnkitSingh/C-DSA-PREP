class Solution
{

private:
    void previousSmallerElement(vector<int> &arr, int n, vector<int> &left)
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];

            while (!st.empty() && arr[st.top()] >= curr)
            {
                st.pop();
            }

            if (st.empty())
            {
                left[i] = 0;
            }
            else
            {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }
    }

    void nextSmallerElement(vector<int> &arr, int n, vector<int> &right)
    {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];

            while (!st.empty() && arr[st.top()] >= curr)
            {
                st.pop();
            }

            if (st.empty())
            {
                right[i] = n - 1;
            }
            else
            {
                right[i] = st.top() - 1;
            }
            st.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        previousSmallerElement(heights, n, left);
        nextSmallerElement(heights, n, right);

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int area = heights[i] * (right[i] - left[i] + 1);
            maxi = max(maxi, area);
        }
        return maxi;
    }
};