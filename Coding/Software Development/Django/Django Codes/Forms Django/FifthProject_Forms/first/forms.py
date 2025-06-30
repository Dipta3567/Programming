from pydoc import text
from django import forms
from django.core import validators # built in validator use kora jonno

# widget use kore form design kora jay

class contactForm(forms.Form):
    Name = forms.CharField(label = "User Name", initial='rahim', help_text='write your name here', required=False, widget=forms.Textarea(attrs= {'id' : 'text_area', 'class' : 'class1', 'placeholder' : 'write your name here'}))
    file = forms.FileField()
    Email = forms.EmailField()
    # Age = forms.IntegerField()
    age = forms.CharField(widget=forms.NumberInput)
    weight = forms.FloatField()
    balance = forms.DecimalField()
    check = forms.BooleanField()
    Birthday= forms.DateField(widget=forms.DateInput(attrs={'type':'date'}))
    appointment = forms.CharField(widget=forms.DateInput(attrs={'type':'datetime-local'}))
    CHOICES=[('S', 'Small'), ('M', 'Medium'), ('L', 'Large')]
    size = forms.ChoiceField(choices=CHOICES, widget=forms.RadioSelect)
    MEAL=[('p', 'Pepperoni'), ('c', 'Cheese'), ('m', 'Mushrooms')]
    pizza = forms.MultipleChoiceField(choices=MEAL, widget=forms.CheckboxSelectMultiple)
    
    
    
    
# class StudentData(forms.Form):
#     name=forms.CharField(widget=forms.TextInput)
#     email = forms.EmailField()
#     # def clean_name(self):
#     #     valname=self.cleaned_data['name']
#     #     if len(valname) < 10:
#     #         raise forms.ValidationError('Name is too short')
#     #     return valname
#     # def clean_email(self):
#     #     valemail=self.cleaned_data['email']
#     #     if '.com' not in valemail:
#     #         raise forms.ValidationError('Email is not valid')
#     #     return valemail
    
#     #e kaj gula rto boto korle kaj bare, to shortcut use korbo
    
#     def clean(self):
#         cleandata=super().clean()
#         valname=cleandata['name']
#         valemail=cleandata['email']
#         if len(valname) < 10:
#              raise forms.ValidationError('Name is too short')
#         if '.com' not in valemail:
#              raise forms.ValidationError('Email is not valid')
        
#         #eta nije nije return kore


def len_check(value):
    if len(value) < 10:
        raise forms.ValidationError('Text is too short')

class StudentData(forms.Form):
    name=forms.CharField(widget=forms.TextInput, validators=[validators.MinLengthValidator(10, message='Name is Short')])
    # name=forms.CharField(widget=forms.TextInput, validators=[validators.MaxLengthValidator(10)])
    
    email = forms.CharField(widget=forms.EmailInput, validators=[validators.EmailValidator(message='Email is not valid')])
    
    age=forms.IntegerField(validators=[validators.MinValueValidator(18, message='User is under age'), validators.MaxValueValidator(60, message='User is over age')])
    
    file= forms.FileField(validators=[validators.FileExtensionValidator(allowed_extensions=['pdf', 'docx'], message='File is not valid')])
    
    # custom validator use kora
    text = forms.CharField(widget=forms.TextInput, validators=[len_check])
    
    
    
class password_validator_project(forms.Form):
    name = forms.CharField(widget=forms.TextInput, validators=[validators.MinLengthValidator(10, message='Name is Short')])
    password = forms.CharField(widget=forms.PasswordInput, validators=[validators.MinLengthValidator(8, message='Password is too short')])
    confirm_password = forms.CharField(widget=forms.PasswordInput, validators=[validators.MinLengthValidator(8, message='Password is too short')])
    
    def clean(self):
        cleandata = super().clean()
        valpassword = cleandata.get('password')
        valconfirm_password = cleandata.get('confirm_password')

        if valpassword and valconfirm_password and valpassword != valconfirm_password:
            raise forms.ValidationError('Password does not match')

        return cleandata
    
      