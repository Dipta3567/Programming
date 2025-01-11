from django.shortcuts import render
from datetime import datetime

# this is one way to access data in html

def home(request):
    context = {
        "days": ['Monday', 'Tuesday', 'Wednesday'],
        "date_value": datetime(2023, 1, 12, 10, 30, 0),
        "text": "Python is Fun",
        "empty_string": "",
    }
    return render(request, "index.html", context)


