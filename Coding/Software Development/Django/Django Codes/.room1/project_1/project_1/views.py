from django.http import HttpResponse

def home(req):
    return HttpResponse("THIS IS THE HOME PAGE")

def contact(req):
    return HttpResponse("THIS IS THE CONTACT PAGE")
