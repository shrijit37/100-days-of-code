#telegram bot 
#do all the coding 
#importing the libraries
import os
import sys
import time
import random
import telebot
from telebot import types
import requests
import json
import urllib
import urllib.request
import urllib.parse

#creating the bot
bot = telebot.TeleBot('TOKEN')

#creating the keyboard
keyboard1 = telebot.types.ReplyKeyboardMarkup(row_width=1, resize_keyboard=True)
keyboard1.add('/start', '/help')

#creating the help message
help_message = '''
Hi, I am Instagram Bot.

#/start - to start the bot
#/help - to get this message
#/follow - to follow a user
#/unfollow - to unfollow a user
#/like - to like a post
#/unlike - to unlike a post
#/comment - to comment on a post
#/uncomment - to uncomment on a post
#/block - to block a user
#/unblock - to unblock a user
#/search - to search a user
#/my_posts - to see your posts
#/my_likes - to see your likes
#/my_followers - to see your followers
#/my_following - to see your following
#/my_comments - to see your comments
'''
#creating the start message
start_message = '''
Hi, I am Instagram Bot.
'''
#creating the follow message
follow_message = '''
Followed the user
'''
#creating the unfollow message
unfollow_message = '''
Unfollowed the user
'''
#creating the like message
like_message = '''
Liked the post
'''
#creating the unlike message
unlike_message = '''
Unliked the post
'''
#creating the comment message
comment_message = '''
Commented on the post
'''
#creating the uncomment message
uncomment_message = '''
Uncommented on the post
'''
#creating the block message
block_message = '''
Blocked the user
'''
#creating the unblock message
unblock_message = '''
Unblocked the user
'''
#creating the search message
search_message = '''
Searched the user
'''
#creating the my_posts message
my_posts_message = '''
Showed your posts
'''
#creating the my_likes message
my_likes_message = '''
Showed your likes
'''
#creating the my_followers message
my_followers_message = '''
Showed your followers
'''
#creating the my_following message
my_following_message = '''
Showed your following
'''
#creating the my_comments message
my_comments_message = '''
Showed your comments
'''
#creating the error message
error_message = '''
Error
'''
#creating the error message
error_message_1 = '''
Error 1
'''
#creating the error message
error_message_2 = '''
Error 2
'''

#creating the function to start the bot
@bot.message_handler(commands=['start'])
def start(message):
    bot.send_message(message.chat.id, start_message, reply_markup=keyboard1)


#creating the function to get the help message
@bot.message_handler(commands=['help'])
def help(message):
    bot.send_message(message.chat.id, help_message)

    #creating the function to follow a user
@bot.message_handler(commands=['follow'])
def follow(message):
    bot.send_message(message.chat.id, 'Enter the username')
    bot.register_next_step_handler(message, follow_username)

    #creating the function to follow a user
def follow_username(message):

    #creating the variables
    username = message.text
    url = 'https://www.instagram.com/' + username + '/?__a=1'
    response = requests.get(url)
    data = response.json()
    user_id = data['graphql']['user']['id']
    url_1 = 'https://www.instagram.com/web/friendships/' + user_id + '/follow/'
    response_1 = requests.post(url_1)
    data_1 = response_1.json()
    bot.send_message(message.chat.id, follow_message)

    #creating the function to unfollow a user
@bot.message_handler(commands=['unfollow'])
def unfollow(message):
    bot.send_message(message.chat.id, 'Enter the username')
    bot.register_next_step_handler(message, unfollow_username)

    #creating the function to unfollow a user
def unfollow_username(message):
    #creating the variables
    username = message.text
    url = 'https://www.instagram.com/' + username + '/?__a=1'
    response = requests.get(url)
    data = response.json()
    user_id = data['graphql']['user']['id']
    url_1 = 'https://www.instagram.com/web/friendships/' + user_id + '/unfollow/'
    response_1 = requests.post(url_1)
    data_1 = response_1.json()
    bot.send_message(message.chat.id, unfollow_message)

    #creating the function to like a post
@bot.message_handler(commands=['like'])
def like(message):
    bot.send_message(message.chat.id, 'Enter the post link')
    bot.register_next_step_handler(message, like_post)

    #creating the function to like a post
def like_post(message):
    #creating the variables
    post_link = message.text
    url = 'https://api.instagram.com/oembed/?url=' + post_link
    response = requests.get(url)
    data = response.json()
    post_id = data['media_id']
    url_1 = 'https://api.instagram.com/v1/media/' + post_id + '/likes'
    response_1 = requests.post(url_1)
    data_1 = response_1.json()
    bot.send_message(message.chat.id, like_message)

    #creating the function to unlike a post
@bot.message_handler(commands=['unlike'])
def unlike(message):
    bot.send_message(message.chat.id, 'Enter the post link')
    bot.register_next_step_handler(message, unlike_post)

    #creating the function to unlike a post
def unlike_post(message):
    #creating the variables
    post_link = message.text
    url = 'https://api.instagram.com/oembed/?url=' + post_link
    response = requests.get(url)
    data = response.json()
    post_id = data['media_id']
    url_1 = 'https://api.instagram.com/v1/media/' + post_id + '/likes'
    response_1 = requests.delete(url_1)
    data_1 = response_1.json()
    bot.send_message(message.chat.id, unlike_message)

    #creating the function to comment on a post
@bot.message_handler(commands=['comment'])
def comment(message):
    bot.send_message(message.chat.id, 'Enter the post link')
    bot.register_next_step_handler(message, comment_post)

    #creating the function to comment on a post
def comment_post(message):
    #creating the variables
    post_link = message.text
    url = 'https://api.instagram.com/oembed/?url=' + post_link
    response = requests.get(url)
    data = response.json()
    post_id = data['media_id']
    bot.send_message(message.chat.id, 'Enter the comment')
    bot.register_next_step_handler(message, comment_post_1)

    #creating the function to comment on a post
def comment_post_1(message):
    #creating the variables
    comment = message.text
    url = 'https://api.instagram.com/v1/media/' + post_id + '/comments'
    payload = {'access_token': '', 'text': comment}
    response = requests.post(url, data=payload)
    data = response.json()
    bot.send_message(message.chat.id, comment_message)

    #creating the function to delete a comment
@bot.message_handler(commands=['delete_comment'])
def delete_comment(message):
    bot.send_message(message.chat.id, 'Enter the post link')
    bot.register_next_step_handler(message, delete_comment_post)

    #creating the function to delete a comment
def delete_comment_post(message):
    #creating the variables
    post_link = message.text
    url = 'https://api.instagram.com/oembed/?url=' + post_link
    response = requests.get(url)
    data = response.json()
    post_id = data['media_id']
    bot.send_message(message.chat.id, 'Enter the comment id')
    bot.register_next_step_handler(message, delete_comment_post_1)

    #creating the function to delete a comment
def delete_comment_post_1(message):
    #creating the variables
    comment_id = message.text
    url = 'https://api.instagram.com/v1/media/' + post_id + '/comments/' + comment_id
    response = requests.delete(url)
    data = response.json()
    bot.send_message(message.chat.id, delete_comment_message)

    #creating the function to get the list of comments
@bot.message_handler(commands=['get_comments'])
def get_comments(message):
    bot.send_message(message.chat.id, 'Enter the post link')
    bot.register_next_step_handler(message, get_comments_post)

    #creating the function to get the list of comments
def get_comments_post(message):

    #creating the variables
    post_link = message.text
    url = 'https://api.instagram.com/oembed/?url=' + post_link
    response = requests.get(url)
    data = response.json()
    post_id = data['media_id']
    url_1 = 'https://api.instagram.com/v1/media/' + post_id + '/comments?access_token='
    response_1 = requests.get(url_1)
    data_1 = response_1.json()
    bot.send_message(message.chat.id, get_comments_message)

    #creating the function to get the list of posts
@bot.message_handler(commands=['get_posts'])
def get_posts(message):
    bot.send_message(message.chat.id, 'Enter the username')
    bot.register_next_step_handler(message, get_posts_username)

    #creating the function to get the list of posts
def get_posts_username(message):
    #creating the variables
    username = message.text
    url = 'https://api.instagram.com/v1/users/search?q=' + username + '&access_token='
    response = requests.get(url)
    data = response.json()
    user_id = data['data'][0]['id']
    url_1 = 'https://api.instagram.com/v1/users/' + user_id + '/media/recent/?access_token='
    response_1 = requests.get(url_1)
    data_1 = response_1.json()
    bot.send_message(message.chat.id, get_posts_message)

    #creating the function to get the list of followers
@bot.message_handler(commands=['get_followers'])
def get_followers(message):
    bot.send_message(message.chat.id, 'Enter the username')
    bot.register_next_step_handler(message, get_followers_username)

#main function
def main():
    bot.polling()

    #main function
if __name__ == '__main__':
    main()

    