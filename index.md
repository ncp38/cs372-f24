---
layout: home
title: Home
nav_exclude: false
nav_order: 0
seo:
  type: Course
  name: Just the Class
---

# {{ site.tagline }}
{: .mb-2 }
{{ site.description }}
{: .fs-6 .fw-300 }

{% if site.announcements %}
{{ site.announcements.last }}
[Announcements](announcements.md){: .btn .btn-outline .fs-3 }
{% endif %}

## Administrivia
- Instructor: Nate Phillips
- Office hours: Tues/Thurs 3:15-4:15 PM & Wed 1-3 PM.  
				Also available by appointment and over Slack or Zoom.
- [Canvas page](https://rhodes.instructure.com/courses/7284): Use for grades, online assignment submissions, and assignment solutions.
- [Syllabus](syllabus/syllabus-372-f24.pdf) and [additional policies](syllabus/additional-policies-372-f24.pdf).

## Resources
- Textbooks and tutorials: *Artificial Intelligence: A Modern Approach*, 4th edition, by Russell and Norvig, Pearson, 2021. (You may also use the older 3rd edition.); 
- Java in the browser: [Repl.it](http://repl.it/new/java), <a href="http://codehs.com">CodeHS</a>;
- <a href="https://docs.oracle.com/en/java/javase/17/docs/api/">Official Java documentation</a>
     

## Calendar
{% for module in site.modules %}
{{ module }}
{% endfor %}

