﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;
namespace UsedGadgetsSale.Models
{
    public class GadgetContext:DbContext
    {
        public GadgetContext() : base("WingtipToys")
    {
        }
        public DbSet<Category> Categories { get; set; }
        public DbSet<Gadget> Gadgets { get; set; }
    }
}
}